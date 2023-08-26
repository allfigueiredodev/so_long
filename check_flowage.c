/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flowage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:51:29 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 14:59:32 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_flowage_c(char **map_copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map_copy[i])
	{
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'P')
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

int	check_flowage_p(char **map_copy)
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

int check_fill_c(char **map_copy, t_point size)
{
	if (!has_walls(map_copy, size))
	{
		ft_printf("Error\nMap has holes on the wall!\n");
		free_map_copy(map_copy);
		return (0);
	}
	if (!check_flowage_c(map_copy))
	{
		ft_printf("Error\nPlayer is trapped\n");
		return (0);
	}
	return(1);
}

int check_fill_p(char **map_copy, t_point size)
{
	if (!has_walls(map_copy, size))
	{
		ft_printf("Error\nMap has holes on the wall!\n");
		free_map_copy(map_copy);
		return (0);
	}
	if (!check_flowage_p(map_copy))
	{
		ft_printf("Error\nPlayer is trapped\n");
		return (0);
	}
	return(1);
}