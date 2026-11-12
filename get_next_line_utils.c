/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:27:05 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/12 21:24:26 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (nmemb > 0 && (size_t)-1 / nmemb < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (nmemb == 0 || size == 0)
		return (ptr);
	if (!ptr)
		return (NULL);
	while (i != nmemb * size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	len;

	i = 0;
	if (!dest)
		return ((char *)src);
	len = ft_strlen(dest);
	if (!src)
		return (dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = ft_calloc(sizeof(char), (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	if (s1)
		str = ft_strcat(str, (char *)s1);
	if (s2)
		str = ft_strcat(str, (char *)s2);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*output;

	i = 0;
	output = (char *)s;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (output[i] == (char)c)
			return (output + i);
		i++;
	}
	if (output[i] == (char)c)
		return (output + i);
	return (NULL);
}
