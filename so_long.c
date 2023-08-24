#include "so_long.h"

int main(int argc, char **argv)
{
	t_wdata wdata;
	t_point w_h;

	if(argc != 2)
	{
		printf("Error\nNo file provided\n");
		return(0);
	}
	set_game_data(&wdata);
	wdata.mapinfo.map = file_to_matrix(&wdata, argv[1]);
	w_h.x = gnl_strlen(wdata.mapinfo.map[0]);
	w_h.y = ft_count_rows(wdata.mapinfo.map);
	if(!map_validator(&wdata, w_h, argv[1]))
	{
		free_matrix(&wdata);
		return(0);
	}
	set_window_data(&wdata, "so_long", wdata.mapinfo.s_width, wdata.mapinfo.s_height);
	set_image_data(&wdata, &wdata.imgdata, argv[1]);
	wdata.imgdata.livemap.live_map = wdata.mapinfo.map;
	render(&wdata, wdata.imgdata.livemap.live_map);
	mlx_hook(wdata.window, KeyPress, KeyPressMask, &on_keypress, &wdata);
	mlx_hook(wdata.window, DestroyNotify, StructureNotifyMask, &on_destroy, &wdata);
	mlx_loop(wdata.init);
	return (0);
}

// to do list:
// make the screen automatically open with the size of the current map - OK
// check about the importance of flood fill - OK
// create functions to print errors - OK
// do basic animation
// fix GNL and libft libs
// create makefile to compile GNL and libft all togheter