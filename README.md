# 1337 CommonCore

Personal systems-programming work from the 42 curriculum and related
low-level programming projects.

This repository collects reusable C foundations developed while studying
memory management, strings, file descriptors, linked lists, and input
processing.

## Repository contents

### Libft

`Libft/` is a static C library that reimplements useful libc functions and
provides additional helpers:

- Character checks and conversion
- Memory operations
- String searching, copying, joining, and trimming
- Integer and string conversion
- File-descriptor output helpers
- Singly linked-list utilities

Build the library from the `Libft` directory:

```sh
cd Libft
make
```

Available targets:

```sh
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Clean and rebuild
```

Use the library by including `libft.h` and linking against `libft.a`.

### Get Next Line

`GNL/` contains the `get_next_line` project:

- `get_next_line.c`
- `get_next_line.h`
- `get_next_line_utils.c`

The project provides line-by-line reading from a file descriptor using a
buffered approach.

## Public project portfolio

| Project | Language | Description |
| --- | --- | --- |
| [ATM Project](https://github.com/ily4sss/ATM_Project) | C++ | Console ATM system with login, balance checks, and money transfers. |
| [ZeroTrace](https://github.com/ily4sss/ZeroTrace) | C++ | Client-server chat system focused on sockets, messaging, storage, and security concepts. |
| [PyScout](https://github.com/ily4sss/PyScout) | Python | CLI tool for inspecting system information, analyzing files, and practicing Python fundamentals. |
| [FOX](https://github.com/ily4sss/Fox) | C | Programming language and mini compiler built from scratch with a lexer, parser, and AST. |
| [HTTP-SERVER](https://github.com/ily4sss/HTTP-SERVER) | C++ | Windows HTTP server built with Winsock for serving static files and handling basic requests. |
| [Packet-Sniffer](https://github.com/ily4sss/Packet-Sniffer) | C++ | Educational Winsock TCP server/client and Npcap packet-sniffing toolkit for Windows. |
| [Permutation & Combination Generator](https://github.com/ily4sss/Cpp-Recursive-Permutation-Combination-Generator) | C++ | Recursive backtracking application that generates permutations and digit combinations. |
| **1337 CommonCore** | C | This repository: reusable 42-style C foundations and input-processing utilities. |

## Focus areas

- C and C++ systems programming
- Memory management and manual resource handling
- Data structures and recursion
- File descriptors and buffered I/O
- TCP/IP networking and sockets
- Compilers and language implementation
- Practical Python CLI tooling

## Requirements

- A C compiler such as `cc` or `clang`
- `make` for the Libft build
- A C++ compiler for the C++ projects
- Windows and Winsock/Npcap for the Windows networking projects

## Notes

The projects are learning-focused and evolve as new concepts are explored.
The inventory above covers the public project repositories associated with
this account; private repositories are intentionally not listed.
