/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:03:32 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 11:51:02 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = NULL;
	while (n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			ptr = (unsigned char *)s;
			return (ptr);
		}
		s++;
		n--;
	}	
	return (ptr);
}
