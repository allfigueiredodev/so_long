/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:59:00 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 16:09:44 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_window_data(t_wdata *wdata, char *title)
{
	wdata->init = mlx_init();
	wdata->window = mlx_new_window(wdata->init, wdata->mapinfo.s_width,
			wdata->mapinfo.s_height, title);
	wdata->title = title;
	wdata->w = wdata->mapinfo.s_width;
	wdata->h = wdata->mapinfo.s_height;
}

void	set_image_data(t_wdata *wdata, t_imgdata *imgdata, char *filename)
{
	int		i;
	char	*sprites[5];

	(void)filename;
	i = 0;
	sprites[0] = "textures/1.xpm";
	sprites[1] = "textures/0.xpm";
	sprites[2] = "textures/P.xpm";
	sprites[3] = "textures/E.xpm";
	sprites[4] = "textures/C.xpm";
	while (i < 5)
	{
		imgdata->sprites[i] = mlx_xpm_file_to_image(wdata->init,
				sprites[i], &wdata->w, &wdata->h);
		i++;
	}
}

void	set_game_data(t_wdata *wdata, char **map)
{
	wdata->game_data.moves = 0;
	wdata->game_data.coins = 0;
	wdata->game_data.coins_collected = 0;
	count_coins(wdata, map);
}
