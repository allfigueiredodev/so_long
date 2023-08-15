#include "so_long.h"

void set_window_data(t_wdata *wdata, char * title, int w, int h)
{
	wdata->init = mlx_init();
	wdata->window = mlx_new_window(wdata->init, w, h, title);
	wdata->title = title;
	wdata->w = w;
	wdata->h = h;
}

// void set_image_data(t_wdata *wdata, t_imgdata *imgdata, int fd)
void set_image_data(t_wdata *wdata, t_imgdata *imgdata, char **path)
{
	int i;

	i = 0;
	// imgdata->img = mlx_xpm_file_to_image(wdata->init, path, &wdata->w, &wdata->h);
	while(i < 5)
	{
		imgdata->sprites[i] = mlx_xpm_file_to_image(wdata->init, path[i], &wdata->w, &wdata->h);
		printf("sprite: %p\n", imgdata->sprites[i]);

		// imgdata->x = 0;
		// imgdata->y = 0;
		i++;
	}
	// imgdata->addr = mlx_get_data_addr(imgdata->img, &imgdata->bpp, &imgdata->line_size, &imgdata->endian);
}


// int on_keypress(int keysym)
int on_keypress(int keysym, t_wdata *wdata)
{
	// (void)wdata;
	printf("Pressed key: %d\n", keysym);
	// controller(keysym, livemap);
	if(keysym == UP || keysym == DOWN || keysym == LEFT || keysym == RIGHT)
		controller(keysym, wdata);
	return (0);
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
	mlx_destroy_window(wdata->init, wdata->window);
	mlx_destroy_display(wdata->init);
	free(wdata->init);
	img_destroy(wdata, &wdata->imgdata);
	exit(0);
	return (0);
}


// int	update(t_wdata *data)
// {
// 	printf("hellow %s\n", data->title);
// 	return (0);
// }

// int main(int argc, char **argv)
int main(void)
{
	t_wdata wdata;
	// int i = 0;
	
	// t_imgdata imgdata;
	// t_livemap livemap;

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
	wdata.imgdata.livemap.live_map = print_map(wdata, &wdata.imgdata, fd, fd2);
	// print_map(wdata, &wdata.imgdata, fd, fd2);
	// img_destroy(&wdata, &wdata.imgdata);
	// mlx_loop_hook(wdata.window, render, &wdata);
	// mlx_key_hook(wdata.init, on_keypress, &wdata);
	mlx_hook(wdata.window, KeyPress, KeyPressMask, &on_keypress, &wdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask, &on_destroy, &wdata);
	mlx_loop(wdata.init);
	// while(wdata.imgdata.livemap.live_map[i])
	// {
	// 	free(wdata.imgdata.livemap.live_map[i]);
	// 	i++;
	// }
	// free(wdata.imgdata.livemap.live_map);
	close(fd);
	close(fd2);
	return (0);
}
