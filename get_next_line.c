/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2026/11/03 17:26:52 by mamatter          #+#    #+#             */
/*   updated: 2026/11/09 09:52:46 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char *buffer, bool *bool_break, int *i)
{
	int	j;

	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (BUFFER_SIZE >= j && (buffer[j] == '\n' || buffer[j]))
		*bool_break = true;
	*i -= BUFFER_SIZE - j;
	return (j);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	bool		bool_break;
	int			i;
	int			j;

	bool_break = false;
	if (fd < 0)
		return (NULL);
	i = 0;
	j = 0;
	line = NULL;
	while (!bool_break)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i += read(fd, buffer, BUFFER_SIZE);
		j = get_line(buffer, &bool_break, &i);
		line = ft_strjoin(line, ft_substr(buffer, 0, j + 1));
		buffer = ft_substr(buffer, j + 1, BUFFER_SIZE);
	}
	line[i + 1] = '\0';
	return (line);
}
