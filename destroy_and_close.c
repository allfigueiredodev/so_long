/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:32:04 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 15:52:46 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_destroy(t_wdata *wdata, t_imgdata *imgdata)
{	
	int	size;

	size = sizeof(imgdata->sprites) / sizeof(imgdata->sprites[0]) - 1;
	while (size)
	{
		mlx_destroy_image(wdata->init, imgdata->sprites[size]);
		size--;
	}
	mlx_destroy_image(wdata->init, imgdata->sprites[size]);
	return (0);
}

int	on_destroy(t_wdata *wdata)
{
	int	i;

	i = 0;
	while (wdata->imgdata.livemap.live_map[i])
	{
		free(wdata->imgdata.livemap.live_map[i]);
		i++;
	}
	free(wdata->imgdata.livemap.live_map);
	img_destroy(wdata, &wdata->imgdata);
	mlx_destroy_window(wdata->init, wdata->window);
	mlx_destroy_display(wdata->init);
	free(wdata->init);
	close(wdata->imgdata.fd);
	exit(0);
}
