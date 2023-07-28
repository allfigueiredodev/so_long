#include "so_long.h"

void set_window_data(t_wdata *wdata, char * title, int w, int h)
{
	wdata->init = mlx_init();
	wdata->window = mlx_new_window(wdata->init, w, h, title);
	wdata->title = title;
	wdata->w = w;
	wdata->h = h;
}

void set_image_data(t_wdata *wdata, t_imgdata *imgdata, char *path)
{
	imgdata->img = mlx_xpm_file_to_image(wdata->init, path, &wdata->w, &wdata->h);
	imgdata->addr = mlx_get_data_addr(imgdata->img, &imgdata->bpp, &imgdata->line_size, &imgdata->endian);
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

int main(void)
{
	t_wdata wdata;
	t_imgdata *imgdata;

	set_window_data(&wdata, "so_long", SWIDTH, SHEIGHT);
	imgdata = malloc(sizeof(t_imgdata));
	if(!imgdata)
		return (0);
	// printf("size of t_imgdata: %lu\n", sizeof(t_imgdata));
	set_image_data(&wdata, imgdata, PATH);
	mlx_put_image_to_window(wdata.init, wdata.window, imgdata->img, 0, 0);
	mlx_hook(wdata.window, KeyRelease, KeyReleaseMask, &on_keypress, &wdata);
	mlx_destroy_image(wdata.init, imgdata->img);
	free(imgdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask, &on_destroy, &wdata);
	mlx_loop(wdata.init);
	free(imgdata);
	return (0);
}