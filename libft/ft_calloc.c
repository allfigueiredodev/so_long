/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:33:48 by aperis-p          #+#    #+#             */
/*   Updated: 2023/06/04 19:17:33 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = NULL;
	if (!nmemb || !size)
		return (malloc(0));
	if (((nmemb * size) / size) != nmemb)
		return (ptr);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
