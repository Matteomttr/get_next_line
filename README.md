*This project has been created as part of the 42 curriculum by mamatter.*

# Get Next Line

## Description

**Get Next Line** is a C function that returns one line at a time from a file descriptor.
The goal of the project is to learn how **open** and **read** work in C
(`<unistd.h>`) and to write clean, well-structured code.

```c
char *get_next_line(int fd);
```

- Each call returns the next line, including the terminating `\n` (except for the last line if the file does not end with one).
- It returns `NULL` when there is nothing left to read or if an error occurs.
- It works with regular files as well as standard input.
- It relies on a **static variable** to keep what has been read but not yet returned between two calls.

Allowed external functions: `read`, `malloc`, `free`.

## Instructions

### Files

| File | Role |
|------|------|
| `get_next_line.c` | Main function |
| `get_next_line_utils.c` | Helper functions |
| `get_next_line.h` | Prototype, includes, `BUFFER_SIZE` default |

### External functions

| Function | Role |
|------|------|
| `ft_strlen` | Returns the length of a string |
| `ft_strncpy` | Copies a string with a specified size |
| `ft_strcat` | Concatenates two strings |
| `ft_strjoin` | Concatenates two strings with a separator |

### Compilation

The buffer size can be set at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

If `-D BUFFER_SIZE` is not provided, a default value is defined in `get_next_line.h`.

### Usage example

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

## Resources

- `man 2 read`, `man 3 malloc`, `man 3 free`

**AI usage:** AI was used only to help write this README. It was not used to write or generate the code of the project.
