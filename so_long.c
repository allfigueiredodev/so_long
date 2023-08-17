#include "so_long.h"

void set_window_data(t_wdata *wdata, char * title, int w, int h)
{
	wdata->init = mlx_init();
	wdata->window = mlx_new_window(wdata->init, w, h, title);
	wdata->title = title;
	wdata->w = w;
	wdata->h = h;
}

void set_image_data(t_wdata *wdata, t_imgdata *imgdata, char **path)
{
	int i;

	i = 0;
	while(i < 5)
	{
		imgdata->sprites[i] = mlx_xpm_file_to_image(wdata->init, path[i], &wdata->w, &wdata->h);
		printf("w: %d\n h: %d\n", wdata->w, wdata->h);
		i++;
	}
}

int img_destroy(t_wdata *wdata, t_imgdata *imgdata)
{	
	int size;

	size = sizeof(imgdata->sprites) / sizeof(imgdata->sprites[0]) - 1;
	while(size)
	{
		mlx_destroy_image(wdata->init, imgdata->sprites[size]);
		size--;
	}
		mlx_destroy_image(wdata->init, imgdata->sprites[size]);

	return (0);
}

int on_destroy(t_wdata *wdata)
{
	int i = 0;
	while(wdata->imgdata.livemap.live_map[i])
	{
		free(wdata->imgdata.livemap.live_map[i]);
		i++;
	}
	free(wdata->imgdata.livemap.live_map);
	img_destroy(wdata, &wdata->imgdata);
	mlx_destroy_window(wdata->init, wdata->window);
	mlx_destroy_display(wdata->init);
	free(wdata->init);
	exit(0);
}

int on_keypress(int keysym, t_wdata *wdata)
{
	printf("Total moves: %d\n", wdata->game_data.moves);
	if(keysym == UP || keysym == DOWN || keysym == LEFT || keysym == RIGHT
	|| keysym == WUP || keysym == SDOWN || keysym == ALEFT || keysym == DRIGHT)
		controller(keysym, wdata);
	else if(keysym == ESC)
		on_destroy(wdata);	
	return (0);
}

int main(void)
{
	t_wdata wdata;

	wdata.game_data.moves = 0;
	char *sprites[5];
	sprites[0] = "assets/wall.xpm";
	sprites[1] = "assets/floor.xpm";
	sprites[2] = "assets/green_ninja.xpm";
	sprites[3] = "assets/stairs.xpm";
	sprites[4] = "assets/scrollPlant.xpm";

	int fd;
	int fd2;

	fd = open(MAP_PATH, O_RDONLY);
	fd2 = open(MAP_PATH, O_RDONLY);
	set_window_data(&wdata, "so_long", SWIDTH, SHEIGHT);
	set_image_data(&wdata, &wdata.imgdata, sprites);
	wdata.imgdata.livemap.live_map = print_map(&wdata, &wdata.imgdata, fd, fd2);
	mlx_hook(wdata.window, KeyPress, KeyPressMask, &on_keypress, &wdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask, &on_destroy, &wdata);
	mlx_loop(wdata.init);
	close(fd);
	close(fd2);
	return (0);
}
