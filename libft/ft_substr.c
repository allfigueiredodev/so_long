/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:23:52 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 11:53:24 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned int		i;
	size_t				j;

	i = start;
	j = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	sub = (char *) malloc(((len + 1) * sizeof(char)));
	if (!sub)
		return (NULL);
	while (i < ft_strlen(s) && j < len)
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
