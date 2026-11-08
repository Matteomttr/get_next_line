/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:26:52 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/08 18:33:52 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*recup_str(char *buffer, bool *bool_break, int *i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (BUFFER_SIZE >= j && (buffer[j] == '\n' || !buffer[j]))
		*bool_break = true;
	*i -= BUFFER_SIZE - j;
	tmp = malloc(sizeof(char) * j);
	tmp = ft_strncpy(tmp, buffer, j);
	return (tmp);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*str;
	static char	*buffer;
	bool		bool_break;

	bool_break = false;
	str = NULL;
	if (fd < 0)
		return (NULL);
	while (!bool_break)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i += read(fd, buffer, BUFFER_SIZE);
		buffer = recup_str(buffer, &bool_break, &i);
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}
