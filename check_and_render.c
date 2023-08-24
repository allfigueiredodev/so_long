/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:18:01 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 13:30:07 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_and_render_up(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (move_up(direction, cur_x, cur_y, wdata))
	{
		render(wdata, livemap);
		return (1);
	}
	return (0);
}

int	check_and_render_down(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (move_down(direction, cur_x, cur_y, wdata))
	{
		render(wdata, livemap);
		return (1);
	}
	return (0);
}

int	check_and_render_left(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (move_left(direction, cur_x, cur_y, wdata))
	{
		render(wdata, livemap);
		return (1);
	}
	return (0);
}

int	check_and_render_right(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char	**livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if (move_right(direction, cur_x, cur_y, wdata))
	{
		render(wdata, livemap);
		return (1);
	}
	return (0);
}
