/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:03:17 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/26 18:12:20 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		{
			if ((*(unsigned char *)s1) == (*(unsigned char *)s2))
			{
				s1++;
				s2++;
			}
			else
			{
				return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
			}
		}
		n--;
	}
	return (0);
}
