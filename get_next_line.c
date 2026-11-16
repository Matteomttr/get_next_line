/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:05:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/16 11:56:28 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	j;
	size_t	len_stay;

	i = 0;
	j = 0;
	while (stay[i] != '\n' && stay[i])
		i++;
	if (stay[i])
		i++;
	len_stay = ft_strlen(&stay[i]);
	new_stay = ft_calloc(sizeof(char), len_stay + 1);
	if (!new_stay)
	{
		free(stay);
		return (NULL);
	}
	while (j < len_stay)
	{
		new_stay[j] = stay[i + j];
		j++;
	}
	free(stay);
	return (new_stay);
}

char	*ft_process_line(char **ptr_stay, char *buffer)
{
	char		*line;

	free(buffer);
	if (!*ptr_stay || !**ptr_stay)
	{
		free(*ptr_stay);
		*ptr_stay = NULL;
		return (NULL);
	}
	line = ft_getline(*ptr_stay);
	*ptr_stay = ft_stay(*ptr_stay);
	if (!*ptr_stay)
		return (NULL);
	return (line);
}

void	ft_free_all(char **ptr_stay, char *buffer)
{
	free(*ptr_stay);
	*ptr_stay = NULL;
	free(buffer);
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
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(stay[fd], '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			ft_free_all(&stay[fd], buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(stay[fd], buffer);
		free(stay[fd]);
		stay[fd] = tmp;
	}
	line = ft_process_line(&stay[fd], buffer);
	return (line);
}
