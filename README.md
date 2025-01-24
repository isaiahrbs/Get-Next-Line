# get_next_line

The `get_next_line` project at 42 aims to create a function that reads a line from a file descriptor, returning the line (without the newline character) and making sure that the file pointer remains in the correct position for subsequent reads.

## Objective

The goal of this project is to implement a function `get_next_line` that:

- Reads a line from a file descriptor.
- Returns the line, not including the newline character.
- Can handle multiple calls, ensuring that the next line is properly read.
- Supports various file descriptors (e.g., standard input, files).
- Handles edge cases like empty lines and the end of the file.

## Function Prototype

```c
char *get_next_line(int fd);
