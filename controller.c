/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:07:01 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 14:30:35 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if (wdata->game_data.coins_collected == wdata->game_data.coins
			&& livemap[cur_y - 1][cur_x] == EXIT)
			on_destroy(wdata);
		livemap[cur_y][cur_x] = FLOOR;
		livemap[cur_y - 1][cur_x] = PLAYER;
		wdata->game_data.moves++;
		return (1);
	}
	else
		return (0);
}

int	move_down(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if (wdata->game_data.coins_collected == wdata->game_data.coins
			&& livemap[cur_y + 1][cur_x] == EXIT)
			on_destroy(wdata);
		livemap[cur_y][cur_x] = FLOOR;
		livemap[cur_y + 1][cur_x] = PLAYER;
		wdata->game_data.moves++;
		return (1);
	}
	else
		return (0);
}

int	move_left(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if (wdata->game_data.coins_collected == wdata->game_data.coins
			&& livemap[cur_y][cur_x - 1] == EXIT)
			on_destroy(wdata);
		livemap[cur_y][cur_x] = FLOOR;
		livemap[cur_y][cur_x - 1] = PLAYER;
		wdata->game_data.moves++;
		return (1);
	}
	else
		return (0);
}

int	move_right(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if (wdata->game_data.coins_collected == wdata->game_data.coins
			&& livemap[cur_y][cur_x + 1] == EXIT)
			on_destroy(wdata);
		livemap[cur_y][cur_x] = FLOOR;
		livemap[cur_y][cur_x + 1] = PLAYER;
		wdata->game_data.moves++;
		return (1);
	}
	else
		return (0);
}

int	controller(int key, t_wdata *wdata)
{
	int		current_x;
	int		current_y;

	set_current(&current_x, &current_y, wdata->imgdata.livemap.live_map);
	if (key == UP || key == WUP)
	{
		if (check_and_render_up(UP, current_x, current_y, wdata))
			return (1);
	}
	else if (key == DOWN || key == SDOWN)
	{
		if (check_and_render_down(DOWN, current_x, current_y, wdata))
			return (1);
	}
	else if (key == LEFT || key == ALEFT)
	{
		if (check_and_render_left(LEFT, current_x, current_y, wdata))
			return (1);
	}
	else if (key == RIGHT || key == DRIGHT)
	{
		if (check_and_render_right(RIGHT, current_x, current_y, wdata))
			return (1);
	}
	return (0);
}
