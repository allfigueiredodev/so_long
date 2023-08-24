/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:45:17 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/24 19:59:53 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (!s || !f)
		return (NULL);
	while (*(s + i))
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
