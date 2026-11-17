*This project has been created as part of the 42 curriculum by mamatter.*

# Get Next Line

## Description

**Get Next Line** is a C function that returns one line at a time from a file descriptor.
The goal of the project is to learn how **open** and **read** work in C
(`<unistd.h>`).

```c
char *get_next_line(int fd);
```

- each call returns the next line, including the terminating `\n` (except for the last line if the file does not end with one).
- it returns `null` when there is nothing left to read or if an error occurs.
- it works with regular files as well as standard input.
- it relies on a **static variable** to keep what has been read but not yet returned between two calls.

Allowed external functions: `read`, `malloc`, `free`.

## Instructions

### Original file

| File | Role |
|------|------|
| `get_next_line.c` | Main funtion returns one line at a time from a file descriptor. |
| `get_next_line_utils.c` | Helper functions |
| `get_next_line.h` | Prototype, includes, `BUFFER_SIZE` default |

### Bonus file

| File | Role |
|------|------|
| `get_next_line_bonus.c` | Main function returns one line at a time from multiple file descriptors. |
| `get_next_line_utils_bonus.c` | Helper functions |
| `get_next_line_bonus.h` | Prototype, includes, `BUFFER_SIZE` and `FD_SIZE` default |

### External functions

| Function | Role |
|------|------|
| `ft_strlen` | Returns the length of a string |
| `ft_strncpy` | Copies a string with a specified size |
| `ft_strcat` | Concatenates two strings |
| `ft_strjoin` | Concatenates two strings with a separator |

### Compilation

The buffer size can be set at compile time.

**Mandatory part:**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

**Bonus part** (multiple file descriptors, using the `_bonus` files):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
```

If `-D BUFFER_SIZE` is not provided, a default value is defined in `get_next_line.h` (and `get_next_line_bonus.h` for the bonus).

### Usage example

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

### Usage example (bonus: multiple file descriptors)

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (1);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		i++;
	}
	return (0);
}
```

## Resources

- `man 2 read`, `man 3 malloc`, `man 3 free`

**AI usage:** AI was used only to help write this README. It was not used to write or generate the code of the project.
