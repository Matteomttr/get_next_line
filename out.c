/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:34:59 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/08 18:07:45 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*size_line(int fd, char	*str)
{
	int			i;
	int			j;
	char		*tmp;
	static char	*buffer;
	int			bool_break;

	bool_break = 0;
	i = 0;
	while (!bool_break)
	{
		j = 0;
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i += read(fd, buffer, BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		while (buffer[j] != '\n' && buffer[j] && buffer[j] != '\0')
			j++;
		if (BUFFER_SIZE >= j && (buffer[j] == '\n' || buffer[j] != '\0'))
			bool_break = true;
		i -= BUFFER_SIZE - j;
		tmp = malloc(sizeof(char) * j);
		tmp = ft_strncpy(tmp, buffer, j);
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	free(buffer);
	str[i] = '\0';
	return (str);
}
