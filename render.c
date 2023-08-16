#include "so_long.h"

void render(t_wdata wdata, t_imgdata *imgdata, char **livemap)
{
	int width;
	int height;
	int i;
	int j;

	width = 0;
	height = 0;
	i = 0;
	j = 0;

	while(livemap[i])
	{
		while(livemap[i][j])
		{
			if(livemap[i][j] == '1')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[0], width, height);
			else if (livemap[i][j] == '0')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[1], width, height);
			else if (livemap[i][j] == 'P')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[2], width, height);
			else if (livemap[i][j] == 'E')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[3], width, height);
			else if (livemap[i][j] == 'C')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[4], width, height);
			width += 47;
			j++;
		}
		height += 47;
		width = 0;
		i++;
		j = 0;
	}
}