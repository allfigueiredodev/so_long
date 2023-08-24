/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:16:09 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 11:52:11 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dupped;

	i = 0;
	dupped = (char *) malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!dupped)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dupped[i] = s[i];
		i++;
	}
	dupped[i] = '\0';
	return (dupped);
}
