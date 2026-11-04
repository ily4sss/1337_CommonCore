*This project has been created as part of the 42 curriculum by ilait-sa.*

# Libft

## Description

Libft is a small personal C library that recreates useful functions from the C standard library and adds a few helpers that are useful in later 42 projects.

The goal is not only to make the functions work. It is to understand what they do, how memory is handled, and what can go wrong at the edges.

The project is split into three parts:

1. **Libc functions**: re-implementations of standard functions, with the same prototypes and behavior as the originals, prefixed with `ft_`.
2. **Additional functions**: string, conversion, and file descriptor output helpers that are not in the libc or exist in a different form.
3. **Linked lists**: a small set of functions to manipulate a singly linked list built on the `t_list` structure.

Everything is compiled into a static library, `libft.a`, and all prototypes are declared in `libft.h`.

## Library description

### Character checks and conversion

These functions inspect or convert one character at a time.

- `ft_isalpha` checks whether a character is a letter.
- `ft_isdigit` checks whether a character is a decimal digit.
- `ft_isalnum` checks whether a character is a letter or a digit.
- `ft_isascii` checks whether a value belongs to the ASCII range.
- `ft_isprint` checks whether a character can be printed.
- `ft_toupper` converts a lowercase letter to uppercase.
- `ft_tolower` converts an uppercase letter to lowercase.

The checking functions return `1` when the character matches the tested class and `0` otherwise. They do not change the original character.

### Memory operations

These functions work with raw memory. They do not need the memory to contain a string or even text.

- `ft_memset` fills a memory area with the same byte.
- `ft_bzero` fills a memory area with zero bytes.
- `ft_memcpy` copies bytes from one memory area to another.
- `ft_memmove` also copies bytes, but safely handles overlapping areas.
- `ft_memchr` searches for a byte in a memory area.
- `ft_memcmp` compares two memory areas byte by byte.
- `ft_calloc` allocates memory and starts it filled with zeros. If `nmemb` or `size` is `0`, it returns a unique pointer that can be safely passed to `free()`.

#### `ft_memcpy` and `ft_memmove`

They both copy `n` bytes.

Use `ft_memcpy` when the source and destination areas do not overlap. It is the simple copy operation.

Use `ft_memmove` when the areas might overlap. It chooses a copy direction that prevents copied bytes from destroying bytes that still need to be read.

A simple example is moving part of an array toward the right. The destination may cover part of the source, so `ft_memmove` is the safer choice.

#### `ft_memset` and `ft_bzero`

`ft_memset` lets you choose the byte to write. `ft_bzero` is the specialized version that always writes zero.

### String length and searching

These functions inspect strings terminated by `\0`.

- `ft_strlen` counts the characters before the terminating null character.
- `ft_strchr` finds the first occurrence of a character.
- `ft_strrchr` finds the last occurrence of a character.
- `ft_strnstr` searches for one string inside another, limited to a maximum length.
- `ft_strncmp` compares up to `n` characters from two strings.

`ft_strchr` searches from the beginning, while `ft_strrchr` searches from the end. Both return a pointer into the original string when they find a match.

### String copying and joining

These functions create, copy, or combine strings.

- `ft_strlcpy` copies a string into a destination buffer with a size limit.
- `ft_strlcat` appends a string while respecting the destination buffer size.
- `ft_strdup` allocates a new string containing a copy of another string.
- `ft_strjoin` allocates a new string made from two strings.
- `ft_substr` allocates a substring starting at a chosen index, with a maximum length.
- `ft_strtrim` allocates a copy of a string with the characters found in a given set removed from its beginning and end.
- `ft_split` separates a string into a `NULL`-terminated array of strings using a delimiter character.

The important difference is ownership: functions such as `ft_strdup`, `ft_strjoin`, `ft_substr`, `ft_strtrim`, and `ft_split` allocate memory. The caller is responsible for freeing the returned memory. For `ft_split`, that means calling `free()` on each string of the array, then on the array itself.

#### `ft_strlcpy` and `ft_strlcat`

Both functions are designed for bounded string operations.

- `ft_strlcpy` replaces the destination content with the source content.
- `ft_strlcat` keeps the existing destination content and appends the source.

The destination size is important because it prevents writing past the buffer when the size is used correctly.

### Number and text conversion

- `ft_atoi` skips leading whitespace, reads an optional sign, then converts the digits that follow to an integer.
- `ft_itoa` allocates a string representation of an integer, negative numbers included.

They go in opposite directions: `ft_atoi` converts text to a number, while `ft_itoa` converts a number to text.

### Functions using callbacks

These functions receive another function as an argument.

- `ft_strmapi` creates a new string and transforms each character with a callback that receives the character and its index.
- `ft_striteri` walks through an existing string and lets a callback modify each character in place, through its address.

`ft_strmapi` returns a new allocated string. `ft_striteri` does not create a new string; it works directly on the string provided by the caller.

### Output to file descriptors

A file descriptor is a small number used by Unix to identify an open destination such as the terminal or a file.

- `ft_putchar_fd` writes one character.
- `ft_putstr_fd` writes a string.
- `ft_putendl_fd` writes a string followed by a newline.
- `ft_putnbr_fd` writes an integer.

The `_fd` suffix means that the destination is chosen by the caller instead of being fixed to standard output.

### Linked lists

The list functions use the `t_list` structure declared in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Each node contains `content` and a pointer to the next node, which is `NULL` for the last node.

- `ft_lstnew` creates one node.
- `ft_lstadd_front` adds a node at the beginning.
- `ft_lstadd_back` adds a node at the end.
- `ft_lstsize` counts the nodes.
- `ft_lstlast` returns the last node.
- `ft_lstdelone` deletes one node using a caller-provided delete function, without touching the next node.
- `ft_lstclear` deletes a node and all its successors, then sets the list pointer to `NULL`.
- `ft_lstiter` applies a function to every node's content.
- `ft_lstmap` creates a new list by transforming each node's content, and uses the delete function to clean up if an allocation fails.

The linked-list functions do not know the real type of `content`; it is stored as `void *`. That makes the list flexible, but it also means the caller must provide correct callback functions for the stored data.

## Instructions

### Compilation

From the root of the repository:

```sh
make
```

This compiles every `ft_*.c` file with `cc` and the flags `-Wall -Wextra -Werror`, so warnings are treated as errors. The objects are then archived with `ar` into `libft.a`, created at the root of the repository.

Available Makefile rules:

| Rule | Effect |
| --- | --- |
| `make` / `make all` | Builds `libft.a`. |
| `make clean` | Removes the object files. |
| `make fclean` | Removes the object files and `libft.a`. |
| `make re` | Runs `fclean`, then rebuilds everything. |

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program and link it with the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

### Technical notes

- No global variables are used.
- Helper functions, when needed, are declared `static` to limit their scope to their own file.
- The `restrict` qualifier is not used in the prototypes, and the code is not compiled with `-std=c99`.
- The library is built with `ar`; `libtool` is not used.

## Resources

The following resources were used to understand C concepts, standard library functions, memory management, and linked lists during the development of Libft.

- **[42 School](https://42.fr/)** — Project requirements and the 42 curriculum.
- **[C Programming Language Reference](https://en.cppreference.com/w/c.html)** — Reference for C language features and standard library functions.
- **[Linux man-pages](https://man7.org/linux/man-pages/)** — Documentation for standard C and Unix functions.
- **[Stack Overflow](https://stackoverflow.com/)** — Community discussions and explanations of C programming problems, pointers, memory management, and edge cases.
- **[GeeksforGeeks](https://www.geeksforgeeks.org/c/c-programming-language/)** — Tutorials and examples covering C programming concepts, pointers, dynamic memory allocation, and linked lists.

### AI Usage

AI tools, including ChatGPT, were used as learning and debugging assistants during the development of this project. Here is what they were used for, and on which parts of the project:

- **Clarifying pointers and pointer-to-pointer variables**, for the linked-list part (`ft_lstadd_front`, `ft_lstadd_back`, `ft_lstclear`), whose functions take a `t_list **`.
- **Understanding linked lists in general**, for the whole linked-list part (`ft_lstnew` to `ft_lstmap`).
- **Understanding memory management and ownership**, for the functions that allocate memory (`ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`) and for freeing what they return.
- **Understanding function behavior and edge cases**, for the libc re-implementations and the additional functions.
- **Analyzing compiler errors, segmentation faults, and potential bugs**, throughout the project while debugging.
- **Suggesting test cases and helping interpret unexpected results**, for my own test programs, which are not part of the submission.
- **Understanding Makefiles, compiler flags, and project requirements**, for the `Makefile` and the subject.

AI was used to support the learning process rather than replace it. The goal was to understand the logic behind each function, write the implementations, test them, and debug problems independently. The final implementations were developed and reviewed as part of my own learning process.
