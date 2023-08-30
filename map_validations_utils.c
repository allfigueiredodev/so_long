/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:42:46 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/27 11:08:16 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_name(char *filename)
{
	int	lenght;

	lenght = ft_strlen(filename);
	if (lenght < 4)
	{
		ft_printf("Error\nWrong file extension\n");
		return (0);
	}
	if (!ft_strcmp((filename + (lenght - 4)), ".ber"))
		return (1);
	ft_printf("Error\nWrong file extension\n");
	return (0);
}

int	has_min_size(t_wdata *wdata, char **map)
{
	int	x;
	int	y;

	x = ft_strlen(map[0]);
	y = ft_count_rows(map);
	wdata->mapinfo.s_width = x * 47;
	wdata->mapinfo.s_height = y * 47;
	if ((x >= 3 && y >= 5) || (y >= 3 && x >= 5))
		return (1);
	else
	{
		ft_printf("Error\nMap doesn't have the minimum size\n");
		return (0);
	}
}

int	is_rectangle(char **map)
{
	int	x;
	int	y;
	int	i;

	x = (int)ft_strlen(map[0]);
	y = ft_count_rows(map);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != x)
		{
			ft_printf("Error\nMap is not in a rectangle shape\n");
			return (0);
		}
		i++;
	}
	if (x == y)
	{
		ft_printf("Error\nMap is not in a rectangle shape\n");
		return (0);
	}
	return (1);
}

int	has_walls(char **map, t_point w_h)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '#')
			return (0);
		i++;
	}
	i = 0;
	while (map[w_h.y - 1][i])
	{
		if (map[w_h.y - 1][i] == '#')
			return (0);
		i++;
	}
	i = 1;
	while (i < w_h.y)
	{
		if (map[i][0] != '#' && map[i][w_h.x - 1] != '#')
			i++;
		else
			return (0);
	}
	return (1);
}
