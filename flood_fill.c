/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:03:11 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/26 13:03:32 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_from_c(char **map, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == '#'
		|| map[cur.y][cur.x] == 'E')
		return ;
	map[cur.y][cur.x] = '#';
	fill_from_c(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_from_c(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_from_c(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill_from_c(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	fill_from_p(char **map, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == '#')
		return ;
	map[cur.y][cur.x] = '#';
	fill_from_p(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_from_p(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_from_p(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill_from_p(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill_c(char **map, t_point size, t_point start)
{
	fill_from_c(map, size, start, map[start.y][start.x]);
}

void	flood_fill_p(char **map, t_point size, t_point start)
{
	fill_from_p(map, size, start, map[start.y][start.x]);
}
