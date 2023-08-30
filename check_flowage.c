/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flowage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:51:29 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/27 10:54:53 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_flowage(char **map_copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map_copy[i])
	{
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
			{
				free_map_copy(map_copy);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_fill(char **map_copy, t_point size)
{
	if (!has_walls(map_copy, size))
	{
		ft_printf("Error\nMap has holes on the wall!\n");
		free_map_copy(map_copy);
		return (0);
	}
	if (!check_flowage(map_copy))
	{
		ft_printf("Error\nPlayer is trapped\n");
		return (0);
	}
	return (1);
}
