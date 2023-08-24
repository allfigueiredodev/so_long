/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:52:15 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/26 17:17:00 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;

	ptr_dest = dest;
	ptr_src = src;
	if (!dest && !src)
		return (0);
	if (ptr_dest <= ptr_src)
	{
		while (n > 0)
		{
			*ptr_dest++ = *ptr_src++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			ptr_dest[n - 1] = ptr_src[n - 1];
			n--;
		}
	}
	return (dest);
}
