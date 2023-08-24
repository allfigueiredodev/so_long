/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:13:23 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/26 19:44:28 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total;
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	total = (ft_strlen(dst)) + (ft_strlen(src));
	dest_size = ft_strlen(dst) + 1;
	src_size = ft_strlen(src) + 1;
	i = 0;
	if (!dst && !src)
		return (0);
	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	while (src[i] && (dest_size + i) < size)
	{
		dst[dest_size - 1 + i] = src[i];
		i++;
	}
	dst[dest_size - 1 + i] = '\0';
	return (total);
}
