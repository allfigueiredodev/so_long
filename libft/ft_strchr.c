/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:59:26 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/26 18:32:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	if (c == '\0')
	{
		while (*s != '\0')
		{
			i++;
			s++;
		}
		return ((char *)s);
	}
	while (*s != '\0')
	{			
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
