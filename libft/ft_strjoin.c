/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:11:50 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/22 20:53:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*new;
	int		k;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((total_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	k = 0;
	while (*s1 != '\0')
	{
		new[k] = *s1;
		s1++;
		k++;
	}
	while (*s2 != '\0')
	{
		new[k] = *s2;
		s2++;
		k++;
	}
	new[k] = '\0';
	return (new);
}
