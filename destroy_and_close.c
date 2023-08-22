#include "so_long.h"

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