/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:04:51 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 16:29:22 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_wdata	wdata;
	t_point	w_h;

	if (argc != 2)
	{
		ft_printf("Error\nNo file provided or more than needed\n");
		return (0);
	}
	wdata.mapinfo.map = file_to_matrix(&wdata, argv[1]);
	set_game_data(&wdata, wdata.mapinfo.map);
	set_screen_size(&w_h, wdata);
	if (!map_validator(&wdata, w_h, argv[1]))
	{
		free_matrix(&wdata);
		return (0);
	}
	set_window_data(&wdata, "so_long");
	set_image_data(&wdata, &wdata.imgdata, argv[1]);
	wdata.imgdata.livemap.live_map = wdata.mapinfo.map;
	render(&wdata, wdata.imgdata.livemap.live_map);
	mlx_hook(wdata.window, KeyPress, KeyPressMask, &on_keypress, &wdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask,
		&on_destroy, &wdata);
	mlx_loop(wdata.init);
	return (0);
}
