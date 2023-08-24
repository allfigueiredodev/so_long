/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:05:56 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/23 16:46:34 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = gnl_strlen(src);
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*p;
	char	*original_s1;
	size_t	len_string;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len_string = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	str = (char *)malloc(len_string);
	if (str == NULL)
		return (NULL);
	p = str;
	original_s1 = s1;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	free(original_s1);
	return (str);
}

size_t	gnl_strlen(const char *s)
{
	int	counter;

	if (s == NULL)
		return (0);
	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}

char	*gnl_strchr(const char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
