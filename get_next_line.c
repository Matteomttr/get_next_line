/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:05:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/11 19:12:31 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *src)
{
	int		j;
	int		i;
	char	*dest;

	j = 0;
	i = 0;
	while (src[j] != '\n' && src[j])
		j++;
	if (src[j] == '\n')
		j++;
	dest = ft_calloc(sizeof(char), (j + 1));
	if (!dest)
		return (NULL);
	while (i != j)
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	return (dest);
}

static char	*buffer_init(char *buffer, int fd, char **line)
{
	int read_bytes;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
	{
		if (*line)
			free(*line);
		return (NULL);
	}
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == 0)
	{
		free(buffer);
		return (NULL);
	}
	if (read_bytes == -1)
	{
		free(buffer);
		if (*line)
			free(*line);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*tmp;
	static char	*stay;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = NULL;
	line = stay;
	while (!line || !ft_strchr(line, '\n'))
	{
		buffer = buffer_init(buffer, fd, &line);
		if (!buffer)
		{
			free(stay);
			stay = NULL;
			return (NULL);
		}
		tmp = ft_strjoin(line, buffer);
		line = tmp;
	}
	free(buffer);
	line = extract_line(line);
	return (line);
}
