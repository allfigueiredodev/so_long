/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:31:45 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/26 18:57:06 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		while (*s1 == *s2 && --n != 0 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
