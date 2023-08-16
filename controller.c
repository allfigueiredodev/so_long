#include "so_long.h"

void controller(int key, t_wdata *wdata)
{
	(void)key;
	int current_x = 0;
	int current_y = 0;
	char **livemap = wdata->imgdata.livemap.live_map;

	set_current(&current_x, &current_y, livemap);
	if(key == UP || key == WUP)
	{
		if(is_next_valid(UP, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x - 1][current_y] = PLAYER;
			wdata->game_data.moves++;
			print_matrix(livemap);
		}
		else
			return;
	}
	else if(key == DOWN || key == SDOWN)
	{
		if(is_next_valid(DOWN, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x + 1][current_y] = PLAYER;
			wdata->game_data.moves++;
			print_matrix(livemap);
		}
		else
			return;
	}
	else if(key == LEFT || key == ALEFT)
	{
		if(is_next_valid(LEFT, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x][current_y - 1] = PLAYER;
			wdata->game_data.moves++;
			print_matrix(livemap);
		}
		else
			return;
	}
	else if(key == RIGHT || key == DRIGHT)
	{
		if(is_next_valid(RIGHT, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x][current_y + 1] = PLAYER;
			wdata->game_data.moves++;
			print_matrix(livemap);
		}
		else
			return;
	}
	render(*wdata, &wdata->imgdata, livemap);
}