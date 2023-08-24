/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:22:27 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 11:51:23 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	conv;
	char			*ptr;

	conv = c;
	ptr = s;
	while (n != 0)
	{
		*ptr = conv;
		ptr++;
		n--;
	}
	return (s);
}
