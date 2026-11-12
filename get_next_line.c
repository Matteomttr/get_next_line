/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:05:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/12 22:15:22 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_getline(char *stay)
{
	char	*line;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (stay[j] != '\n' && stay[j])
		j++;
	if (stay[j] == '\n')
		j++;
	line = ft_calloc(sizeof(char), j + 1);
	if (!line)
		return (NULL);
	while (i < j)
	{
		line[i] = stay[i];
		i++;
	}
	return (line);
}

char	*ft_stay(char *stay)
{
	char	*new_stay;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stay[i] != '\n' && stay[i])
		i++;
	i++;
	new_stay = ft_calloc(sizeof(char), ft_strlen(&stay[i]) + 1);
	if (!new_stay)
		return (NULL);
	while (j < ft_strlen(&stay[i]))
	{
		new_stay[j] = stay[i + j];
		j++;
	}
	free(stay);
	return (new_stay);
}

char	*ft_process_line(char **ptr_stay)
{
	char		*line;

	line = ft_getline(*ptr_stay);
	if (!line)
		return (NULL);
	*ptr_stay = ft_stay(*ptr_stay);
	if (!*ptr_stay)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stay[1024];
	int			read_bytes;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stay[fd], '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(stay[fd]);
			free(buffer);
			return (NULL);
		}
		tmp = ft_strjoin(stay[fd], buffer);
		free(stay[fd]);
		stay[fd] = tmp;
	}
	line = ft_process_line(&stay[fd]);
	free(buffer);
	return (line);
}
