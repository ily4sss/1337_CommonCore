*This project has been created as part of the 42 curriculum by ilait-sa.*

# get_next_line

## Description

**get_next_line** is a C function that returns one line at a time from a file descriptor.

```c
char *get_next_line(int fd);
```

Calling the function repeatedly reads a text file line by line, until there is nothing left to read.

**Goal.** The project teaches how `read()` really works (it returns raw bytes, not lines), how to keep data between calls with a `static` variable, and how to manage heap memory without leaks.

**Behavior.**

- It returns the line that was read, **including the terminating `\n`**.
- The last line has no `\n` if the file does not end with one.
- It returns `NULL` when there is nothing left to read, or when an error occurs (invalid fd, `read()` failure, `malloc` failure).
- It works on regular files, on standard input (fd `0`)...


**Files.**

| Part | Files |
|---|---|
| Mandatory | `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h` |
| Bonus | `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h` |

**Bonus.** The bonus version manages several file descriptors at the same time, with **only one static variable**. You can read from fd 3, then fd 4, then fd 5, then fd 3 again, and each fd keeps its own reading state.

**Constraints respected.** Allowed functions are only `read`, `malloc` and `free`. No `libft`, no `lseek()`, no global variables.

## Instructions

### Compilation

The project compiles with or without the `-D BUFFER_SIZE=n` flag. The default value is `42`, defined in the header only if the flag is not given.

```sh
# Mandatory part, with a chosen buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Mandatory part, using the default buffer size
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl

# Bonus part
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

`main.c` is a personal test program. It is not part of the submission.

### Usage

Include the header and call the function in a loop. Each returned line must be freed by the caller.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

Reading from standard input:

```sh
printf 'first\nsecond' | ./gnl
```

Reading two files at the same time (bonus):

```c
a = get_next_line(fd_a);   /* A1 */
b = get_next_line(fd_b);   /* B1 */
a = get_next_line(fd_a);   /* A2, not a line of B */
```

### Testing

Tests I used during development:

- Edge-case files: empty file, a file with only `\n`, only newlines, one character without `\n`, a last line without `\n`, empty lines between lines.
- Invalid file descriptors (`-1`, `1024`(SoftLimit in my computer), a closed fd).
- Standard input.
- Several fds read in alternation (bonus).
- Memory: `-fsanitize=address -g` (AddressSanitizer with LeakSanitizer), and `valgrind --leak-check=full` on a build **without** the sanitizer. The two tools must not be combined on the same binary.

## Algorithm

### Overview

The function keeps a **stash**: a heap string holding the bytes already read from the fd but not yet returned. The stash is stored in a `static` variable, so it survives between calls.

Four things are kept separate:

| Name | Role |
|---|---|
| `buffer` | Temporary area filled by one `read()`. It is overwritten by the next `read()`. |
| `stash` | Accumulates the buffers read so far. Persistent (static). |
| `line` | The string returned to the caller (a new heap block). |
| `leftover` | What remains in the stash after the line is cut out. It becomes the new stash. |

### Why this algorithm

- **`read()` only gives raw bytes.** A chunk can contain no newline, one newline, several newlines, or a newline followed by the start of the next line. Accumulating chunks in a stash and cutting at the first `\n` handles all these cases in the same way.
- **The buffer is temporary.** Each `read()` overwrites it, so its content must be added to the stash before the next `read()`.
- **Only the valid bytes are used.** `read()` does not add a `'\0'`, and bytes after the first `n` bytes are stale. The code writes the terminator at `buffer[n]`, so the stale bytes never enter the stash.
- **The leftover is a new heap block, never a pointer into the old stash.** A pointer into a block dies when that block is freed, and `free()` accepts only the exact pointer returned by `malloc`. Copying the leftover lets the old stash be freed safely.
- **Reads as little as possible.** The loop stops as soon as the stash contains a `\n`, as the subject requires. If the stash already contains a full line from a previous read, no `read()` happens.
- **Any valid `BUFFER_SIZE` works.** With `1`, the loop runs many times. With a huge value, one `read()` takes the whole file and the later calls only use the stash. The line length and the buffer size are independent.
- **EOF is detected only by `read()` returning `0`.** A `read()` that returns fewer bytes than asked does not mean EOF. A return of `-1` is an error and makes the function return `NULL`.

### Memory management

- The old stash is freed right after the join has copied it (using a temporary pointer), so each loop round does not leak.
- The buffer is freed on every exit path, including the error path.
- When nothing is left, the stash is freed and set to `NULL`, so the next call on the same fd starts clean. This also avoids a use-after-free or a double free.
- If the allocation of the leftover fails, the line and the stash are freed and `NULL` is returned.
- `free(NULL)` is safe, so the first call (stash is `NULL`) needs no special case.
- The buffer is freed on every exit path. The two error cases inside the read loop (`read()` returns `-1`, or `ft_strjoin` fails) go through one helper, `clean_exit`. It frees the buffer, frees the current stash, sets the static pointer to `NULL`, and returns `0`, so `get_next_line` returns `NULL`.
- Each block has one owner that frees it. The old stash is freed by the read loop right after the join, and the current stash is freed by `clean_exit` on an error. `clean_exit` does not free the old stash, to avoid a double free. `free(NULL)` is safe, so a failed join needs no special case.

### Bonus: several file descriptors

The mandatory version has one `static char *stash`. The bonus version replaces it with one `static char *stash[1024]`: the stash of fd `n` is `stash[n]`. This is still **one static variable**, but each fd owns its own slot, so reading fd 3 never touches the leftover of fd 4.

This mirrors what the kernel does: each open file has its own offset, and the program must keep its own leftover for each fd.

An fd outside `0..1023` makes the function return `NULL`, so the array is never accessed out of bounds.

### Limitations

- The bonus supports fds up to `1023`.
- As the subject states, the behavior is undefined if the file is modified between calls before EOF, and for binary files.

## Resources

### Documentation and references

- `man 2 read`, `man 2 open`, `man 2 close`, `man 3 malloc`, `man 3 free`:
  - https://man7.org/linux/man-pages/man2/read.2.html
  - https://man7.org/linux/man-pages/man2/open.2.html
  - https://man7.org/linux/man-pages/man3/malloc.3.html
- C `static` variables: storage duration, initialization to zero, and the `.bss` / `.data` sections.
- File descriptors, the per-process fd table, open file descriptions (the file offset) and inodes: Linux man pages (`man 2 open`, `man 7 inode`) and the Linux kernel VFS documentation.
- The 42 Norm and the subject of the project.
- Discussions with peers about edge cases and test files.

### How AI was used

I used an AI assistant as a **mentor**, not as a code generator. I wrote the `get_next_line` functions myself.

| Task | How AI was used |
|---|---|
| Understanding concepts | Step-by-step explanations with text diagrams: what `BUFFER_SIZE` means, how `read()` and its return value work, the offset, file descriptors and the fd table, `static` variables and where they live in memory, stack versus heap, pointer arithmetic. |
| Design | Questions and hints (Socratic style) that helped me find the structure: a read loop, a stash, cutting the line, keeping the leftover as a new block. |
| Code review and debugging | Pointed at the exact line and showed a trace of the failure, and I fixed it myself. Examples: the `malloc` size off-by-one in the line copy, the static variable being reset on every call, the lost data in `ft_strjoin` when the stash is `NULL`, the loop that never ended at EOF, and memory leaks found with AddressSanitizer. A few of the small fixes (for example freeing the stash and setting it to `NULL` before returning `NULL`) were suggested during review, and I applied them after tracing why they are needed. |
| Documentation | Help with the structure and the wording of this README. I checked that it describes my own code. |
