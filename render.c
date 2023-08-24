/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:53:48 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/24 13:56:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_chr(t_wdata *wdata, char chr, int width, int height)
{
	if (chr == '1')
		mlx_put_image_to_window(wdata->init, wdata->window,
			wdata->imgdata.sprites[0], width, height);
	else if (chr == '0')
		mlx_put_image_to_window(wdata->init, wdata->window,
			wdata->imgdata.sprites[1], width, height);
	else if (chr == 'P')
		mlx_put_image_to_window(wdata->init, wdata->window,
			wdata->imgdata.sprites[2], width, height);
	else if (chr == 'E')
		mlx_put_image_to_window(wdata->init, wdata->window,
			wdata->imgdata.sprites[3], width, height);
	else if (chr == 'C')
		mlx_put_image_to_window(wdata->init, wdata->window,
			wdata->imgdata.sprites[4], width, height);
}

void	render(t_wdata *wdata, char **map)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = 0;
	height = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			render_chr(wdata, map[i][j], width, height);
			width += 47;
			j++;
		}
		height += 47;
		width = 0;
		i++;
		j = 0;
	}
}
