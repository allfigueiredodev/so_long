/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_trapped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:42:02 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 15:00:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_trapped(t_wdata *wdata, char **map)
{
	t_point	size;
	t_point	player;
	char	**map_copy;
	int		i;
	int		j;

	size.x = wdata->mapinfo.s_width / 47;
	size.y = wdata->mapinfo.s_height / 47;
	i = 0;
	j = 0;
	clone_matrix(&map_copy, map, size.x, size.y);
	set_current(&player.x, &player.y, map_copy);
	flood_fill(map_copy, size, player);
	if (!check_flowage(map_copy))
		return (0);
	free_map_copy(map_copy);
	return (1);
}
