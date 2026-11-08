/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:27:14 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 09:34:01 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*get_next_line(int fd);

#endif
