#include "so_long.h"

void set_window_data(t_wdata *wdata, char * title, int w, int h)
{
	wdata->init = mlx_init();
	wdata->window = mlx_new_window(wdata->init, w, h, title);
	wdata->title = title;
	wdata->w = w;
	wdata->h = h;
}

void set_image_data(t_wdata *wdata, t_imgdata *imgdata, char *filename)
{
	int i;
	char *sprites[5];

	i = 0;
	sprites[0] = "textures/1.xpm";
	sprites[1] = "textures/0.xpm";
	sprites[2] = "textures/P.xpm";
	sprites[3] = "textures/E.xpm";
	sprites[4] = "textures/C.xpm";
	imgdata->fd = open(filename, O_RDONLY);
	imgdata->fd2 = open(filename, O_RDONLY);
	while(i < 5)
	{
		imgdata->sprites[i] = mlx_xpm_file_to_image(wdata->init, sprites[i], &wdata->w, &wdata->h);
		i++;
	}
}

void set_game_data(t_wdata *wdata)
{
    wdata->game_data.moves = 0;
	wdata->game_data.coins = 0;
	wdata->game_data.coins_collected = 0;
}