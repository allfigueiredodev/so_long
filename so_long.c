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
		i++;
	}
	// imgdata->addr = mlx_get_data_addr(imgdata->img, &imgdata->bpp, &imgdata->line_size, &imgdata->endian);
}

int on_keypress(int keysym, t_wdata *wdata)
{
	(void)wdata;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

int on_destroy(t_wdata *wdata)
{
	mlx_destroy_window(wdata->init, wdata->window);
	mlx_destroy_display(wdata->init);
	free(wdata->init);
	exit(0);
	return (0);
}

void print_map(t_wdata wdata, t_imgdata *imgdata, int fd)
{	
	int width = 0;
	int height = 0;
	char *string;
 
	string = get_next_line(fd);
	while (string)
	{
		while(*string)
		{
				// mlx_put_image_to_window(wdata.init, wdata.window, imgdata->img, width, height);
			if(*string == '1')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[0], width, height);
			else if (*string == '0')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[1], width, height);
			else if (*string == 'P')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[2], width, height);
			else if (*string == 'E')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[3], width, height);
			else if (*string == 'C')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[4], width, height);
			width += 47;
			string++;
		}	
		height += 47;
		width = 0;
		string = get_next_line(fd);
	}
}

// int main(int argc, char **argv)
int main(void)
{
	t_wdata wdata;
	t_imgdata *imgdata;
	char *sprites[5];
	sprites[0] = "assets/wall.xpm";
	sprites[1] = "assets/floor.xpm";
	sprites[2] = "assets/green_ninja.xpm";
	sprites[3] = "assets/stairs.xpm";
	sprites[4] = "assets/scrollPlant.xpm";
	int fd;

	fd = open(MAP_PATH, O_RDONLY);
	set_window_data(&wdata, "so_long", SWIDTH, SHEIGHT);
	imgdata = malloc(sizeof(t_imgdata));
	if(!imgdata)
		return (0);
	set_image_data(&wdata, imgdata, sprites);
	print_map(wdata, imgdata, fd);
	mlx_hook(wdata.window, KeyRelease, KeyReleaseMask, &on_keypress, &wdata);
	// mlx_destroy_image(wdata.init, imgdata->img);
	free(imgdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask, &on_destroy, &wdata);
	mlx_loop(wdata.init);
	return (0);
}
