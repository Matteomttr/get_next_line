/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:05:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/11 17:53:08 by mamatter         ###   ########.fr       */
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
	dest = ft_calloc(sizeof(char), (j + 2));
	while (i != j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	return (dest);
}

static char	*buffer_init(char *buffer, int fd, int *i, char **line)
{
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
	{
		if (*line)
			free(*line);
		return (NULL);
	}
	*i = read(fd, buffer, BUFFER_SIZE);
	if (*i == 0)
	{
		free(buffer);
		return (NULL);
	}
	if (*i < 0)
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
	static char	*stay = NULL;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = NULL;
	line = stay;
	i = 0;
	while (!ft_strchr(line, '\n'))
	{
		buffer = buffer_init(buffer, fd, &i, &line);
		if (!buffer)
			return (NULL);
		line = ft_strjoin(line, buffer);
		free(buffer);
	}
	stay = ft_strchr(line, '\n') + 1;
	line = extract_line(line);
	return (line);
}
