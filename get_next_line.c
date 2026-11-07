/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:26:52 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/07 12:10:29 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*size_line(int fd, char	*str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*buffer;
	int		bool_break;

	bool_break = 0;
	while (!bool_break)
	{
		j = 0;
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i += read(fd, buffer, BUFFER_SIZE);
		while (buffer[j] != '\n' && buffer[j])
			j++;
		if (BUFFER_SIZE >= j && buffer[j] == '\n')
			bool_break = 1;
		i -= BUFFER_SIZE - j;
		tmp = malloc(sizeof(char) * j);
		tmp = ft_strncpy(tmp, buffer, j);
		str = ft_strjoin(str, tmp);
		free(buffer);
		free(tmp);
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = size_line(fd, str);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	close(fd);
	return (0);
}
