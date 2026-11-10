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

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	bool		bool_break;
	char		*line;
	static char	*stay = NULL;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	i = 0;
	bool_break = false;
	while (!bool_break)
	{
		j = 0;
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
		while (buffer[j] != '\n' && buffer[j])
			j++;
		if (BUFFER_SIZE >=j && buffer[j] == '\n')
			bool_break = true;
		line = ft_strjoin(line, ft_strjoin(stay, ft_substr(buffer, 0, j + 1)));
		stay = ft_substr(buffer, j + 1, BUFFER_SIZE);
	}
	free(buffer);
	line[ft_strlen(line) + 1] = '\0';
	return (line);
}
