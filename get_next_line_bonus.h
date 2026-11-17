/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:27:14 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 09:34:01 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* Buffer size used by read(). */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* File directory size used by static variable. */
# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

/* Inclusion of necessary libraries */
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/* Function utils resumption of libft */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);

/* Main function */
char	*get_next_line(int fd);

#endif
