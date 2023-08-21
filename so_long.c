#include "so_long.h"

void set_window_data(t_wdata *wdata, char * title, int w, int h)
{
	wdata->init = mlx_init();
	wdata->window = mlx_new_window(wdata->init, w, h, title);
	wdata->title = title;
	wdata->w = w;
	wdata->h = h;
}

void set_image_data(t_wdata *wdata, t_imgdata *imgdata, char **path, char *filename)
{
	int i;

	i = 0;
	imgdata->fd = open(filename, O_RDONLY);
	imgdata->fd2 = open(filename, O_RDONLY);
	while(i < 5)
	{
		imgdata->sprites[i] = mlx_xpm_file_to_image(wdata->init, path[i], &wdata->w, &wdata->h);
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
	close(wdata->imgdata.fd);
	close(wdata->imgdata.fd2);
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

int main(int argc, char **argv)
{
	t_wdata wdata;
	
	if(argc != 2)
	{
		printf("No file provided\n");
		return(0);
	}
	set_game_data(&wdata);

	char *sprites[5];
	sprites[0] = "assets/wall.xpm";
	sprites[1] = "assets/floor.xpm";
	sprites[2] = "assets/green_ninja.xpm";
	sprites[3] = "assets/stairs.xpm";
	sprites[4] = "assets/scrollPlant.xpm";

	set_window_data(&wdata, "so_long", SWIDTH, SHEIGHT);
	set_image_data(&wdata, &wdata.imgdata, sprites, argv[1]);
	wdata.mapinfo.map = file_to_matrix(&wdata, argv[1]);
	if(!map_validator(&wdata, argv[1]))
	{
		printf("Invalid file, check min 2d size, format and etc...\n");
		on_destroy(&wdata);
		return(0);
	}
	wdata.imgdata.livemap.live_map = wdata.mapinfo.map;
	render(&wdata, wdata.imgdata.livemap.live_map);
	mlx_hook(wdata.window, KeyPress, KeyPressMask, &on_keypress, &wdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask, &on_destroy, &wdata);
	mlx_loop(wdata.init);
	return (0);
}

// to do list:
// make the screen automatically open with the size of the current map
// check about the importance of flood fill
// create functions to print errors
// do basic animation
// fix GNL and libft libs
// create makefile to compile GNL and libft all togheter