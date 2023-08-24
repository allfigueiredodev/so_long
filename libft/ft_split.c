/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:32:16 by aperis-p          #+#    #+#             */
/*   Updated: 2023/05/25 12:34:33 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_del_count(char const *s, char c)
{
	size_t		counter;
	char const	*ptr;
	int			i;

	ptr = s;
	counter = 0;
	i = 0;
	while (*(ptr + i))
	{
		while (*(ptr + i) == c && *(ptr + i) != '\0')
			i++;
		while (*(ptr + i) != c && *(ptr + i) != '\0')
			i++;
		if (*(ptr + i) != '\0' || *(ptr + i - 1) != c)
			counter++;
	}
	return (counter);
}

static	int	ft_btw(char const *s, char c)
{
	int			counter;
	char const	*ptr;
	int			i;

	ptr = s;
	if (*(ptr + 0) == c)
		i = 1;
	else
		i = 0;
	counter = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == c)
		{
			return (counter);
		}
		counter ++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	char		**temp;

	result = (char **) malloc((ft_del_count(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	temp = result;
	while (*s)
	{
		if (*s != c)
		{
			*temp = malloc((ft_btw(s, c) + 1) * sizeof(char));
			if (*temp == NULL)
				return (NULL);
			ft_strlcpy(*temp++, s, ft_btw(s, c) + 1);
			s += ft_btw(s, c);
		}
		else
			s++;
	}
	*temp = NULL;
	return (result);
}
