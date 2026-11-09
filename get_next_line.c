/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:26:52 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/09 09:52:46 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char *buffer, bool *break_bool, int *i)
{
	int	j;

	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (BUFFER_SIZE >= j && buffer[j] == '\n')
		*break_bool = true;
	*i -= BUFFER_SIZE - j;
	return (j);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line = NULL;
	bool		break_bool;
	int			i;
	int			j;

	if (fd < 0)
		return (NULL);
	break_bool = false;
	i = 0;
	j = 0;
	while (!break_bool)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i += read(fd, buffer, BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		j = get_line(buffer, &break_bool, &i);
		buffer = ft_substr(buffer, 0, j);
		line = ft_strjoin(line, buffer);
		free(buffer);
	}
	line[i + 1] = '\0';
	return (line);
}
