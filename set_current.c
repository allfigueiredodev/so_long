/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:56:47 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 14:26:43 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_current(int *x, int *y, char **livemap)
{
	int	i;
	int	j;

	*x = 0;
	*y = 0;
	i = *y;
	j = *x;
	while (livemap[i][j] && livemap[i][j != 'P'])
	{
		while (livemap[i][j] && livemap[i][j] != 'P')
			j++;
		if (livemap[i][j] != 'P')
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	*x = j;
	*y = i;
}

void	get_first_c(int *x, int *y, char **livemap)
{
	int	i;
	int	j;

	*x = 0;
	*y = 0;
	i = *y;
	j = *x;
	while (livemap[i][j] && livemap[i][j != 'C'])
	{
		while (livemap[i][j] && livemap[i][j] != 'C')
			j++;
		if (livemap[i][j] != 'C')
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	*x = j;
	*y = i;
}
