#include "so_long.h"

void moves_on_display(t_wdata *wdata)
{
	char *moves;

	moves = ft_itoa(wdata->game_data.moves);
	mlx_set_font(wdata->init, wdata->window, "-Misc-Fixed-Bold-R-Normal--15-140-75-75-C-90-ISO10646-1");
	mlx_string_put(wdata->init, wdata->window , 50, 60, 0x000000,"Total moves: ");
	mlx_string_put(wdata->init, wdata->window , 160, 60, 0x000000, moves);
	free(moves);
	moves = NULL;
}