# Get Next Line

This repository contains an implementation of the `get_next_line` function, a fundamental part of the 42Network curriculum at 1337 School. The `get_next_line` function is designed to read lines from a file descriptor, making it a crucial tool for various programming tasks involving file I/O operations.

## Introduction

The `get_next_line` function reads lines from a file descriptor (fd) one by one until the end of the file (EOF) is reached or an error occurs. It dynamically allocates memory to store the read lines, ensuring efficient memory usage and preventing memory leaks.

## Features

- Reads lines from a file descriptor
- Handles dynamic memory allocation
- Supports reading from multiple file descriptors simultaneously
- Customizable buffer size

## Usage

To use the `get_next_line` function in your C project, follow these steps:

1. Include the `get_next_line.h` header file in your source files.
2. Call the `get_next_line` function with the file descriptor (fd) as the argument.
3. The function returns the next line from the file descriptor, or NULL if there are no more lines or an error occurs.
4. Free the memory allocated by the function when no longer needed.

Example usage:

```c
#include "get_next_line.h"
#include <fcntl.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        // Do something with the line
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}

```

## How It Works

The `get_next_line` function operates by reading characters from a file descriptor (fd) into a buffer. It then scans the buffer for newline characters ('\n') to identify complete lines. If a newline character is found within the buffer, the function extracts the line up to that point and returns it. If no newline character is found, the function continues reading from the file descriptor until it encounters a newline character or reaches the end of the file (EOF).

Internally, the function manages memory dynamically to accommodate lines of varying lengths. It utilizes a static variable to keep track of the data left over from previous calls, ensuring that partial lines are correctly processed when subsequent calls are made.

The function employs a customizable buffer size, allowing users to adjust the amount of data read from the file descriptor with each iteration. This flexibility enables efficient memory usage and performance optimization based on specific application requirements.

Upon reaching the end of the file or encountering an error during reading, the function returns NULL, signaling the end of the line reading process.
