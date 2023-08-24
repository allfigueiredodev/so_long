/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:37:26 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/26 19:42:24 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = NULL;
	i = 0;
	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (*big && i < len)
	{
		if (*little == *big)
		{
			if (i + ft_strlen(little) > len)
				return (NULL);
			if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			{
				ptr = (char *)big;
				return (ptr);
			}				
		}
		big++;
		i++;
	}
	return (ptr);
}
