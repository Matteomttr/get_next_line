/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:05:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/17 11:57:33 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Extracts the next line from the stored buffer. */
static char	*ft_getline(char *stay)
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

/* Keeps the remaining characters after the extracted line. */
static char	*ft_stay(char *stay)
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

/* Processes the extracted line and updates the stored buffer. */
static char	*ft_process_line(char **ptr_stay, char *buffer)
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

/* Reads data from the file descriptor and appends it to the buffer. */
static void	ft_read_file(char **stay, char *buffer, int *read_bytes, int fd)
{
	char	*tmp;

	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes == -1)
	{
		free(*stay);
		*stay = NULL;
		return ;
	}
	buffer[*read_bytes] = '\0';
	tmp = ft_strjoin(*stay, buffer);
	free(*stay);
	*stay = tmp;
}

/* Main funtion returns one line at a time from a file descriptor. */
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stay;
	int			read_bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(stay, '\n'))
	{
		ft_read_file(&stay, buffer, &read_bytes, fd);
		if (!stay)
		{
			free(buffer);
			return (NULL);
		}
	}
	line = ft_process_line(&stay, buffer);
	return (line);
}
