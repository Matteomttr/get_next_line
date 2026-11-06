/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:26:52 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/06 11:58:51 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	sizeLine(int fd, char	**str)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	j = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i += read(fd, tmp, BUFFER_SIZE);
	while (tmp[j] != '\n' || tmp[j])
		j++;
	i -= BUFFER_SIZE - j;
	free(tmp - (BUFFER_SIZE - j));
	size = ft_strjoin(*str, tmp);
	free(tmp);
	return (size);
}

char	*get_next_line(int fd)
{
	char	*str;
	int		count;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	count = read(fd, str, BUFFER_SIZE);
	return (str);
}

#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	i = open(argv[1], O_RDONLY);
	write(1, get_next_line(i), BUFFER_SIZE);
	return (0);
}
