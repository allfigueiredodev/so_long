/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:56:47 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/27 19:20:49 by aperis-p         ###   ########.fr       */
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
