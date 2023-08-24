#include "so_long.h"

int is_next_valid(int key, int x, int y, t_wdata *wdata)
{
	int next_x = x;
	int next_y = y;

	ft_printf("total coins rendered: %d\n", wdata->game_data.coins);
	ft_printf("coins already collected: %d\n", wdata->game_data.coins_collected);

	if(key == UP || key == WUP)
		next_y = next_y - 1;
	else if(key == DOWN || key == SDOWN)
		next_y = next_y + 1;
	else if(key == LEFT || key == ALEFT)
		next_x = next_x - 1;
	else if(key == RIGHT || key == DRIGHT)
		next_x = next_x + 1;
	if(wdata->imgdata.livemap.live_map[next_y][next_x] == WALL)
		return(0);
	if(wdata->imgdata.livemap.live_map[next_y][next_x] == COL)
		wdata->game_data.coins_collected++;
	if(wdata->imgdata.livemap.live_map[next_y][next_x] == EXIT && wdata->game_data.coins_collected != wdata->game_data.coins)
		return(0);
	else if(wdata->imgdata.livemap.live_map[next_y][next_x] == EXIT && wdata->game_data.coins_collected == wdata->game_data.coins)
		return(1);
	else
		return(1);
}