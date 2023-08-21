#include "so_long.h"

void render(t_wdata *wdata, char **map)
{
	int width;
	int height;
	int i;
	int j;

	width = 0;
	height = 0;
	i = 0;
	j = 0;

	while(map[i])
	{
		while(map[i][j])
		{
			if(map[i][j] == '1')
				mlx_put_image_to_window(wdata->init, wdata->window, wdata->imgdata.sprites[0], width, height);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(wdata->init, wdata->window, wdata->imgdata.sprites[1], width, height);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(wdata->init, wdata->window, wdata->imgdata.sprites[2], width, height);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(wdata->init, wdata->window, wdata->imgdata.sprites[3], width, height);
			else if (map[i][j] == 'C')				
				mlx_put_image_to_window(wdata->init, wdata->window, wdata->imgdata.sprites[4], width, height);
			width += 47;
			j++;
		}
		height += 47;
		width = 0;
		i++;
		j = 0;
	}
}