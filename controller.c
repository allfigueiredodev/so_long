#include "so_long.h"

// void controller(int key, char **livemap)
void controller(int key, t_wdata *wdata)
{
	(void)key;
	// printf("%d\n", key);
	// printf("%c\n", wdata->imgdata.livemap.live_map[6][5]);
	int current_x = 0;
	int current_y = 0;
	char **livemap = wdata->imgdata.livemap.live_map;

	set_current(&current_x, &current_y, livemap);
	// printf("x: %d y: %d\n", current_x, current_y);
	// print_matrix(livemap);

	if(key == UP)
	{
		if(is_next_valid(UP, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x - 1][current_y] = PLAYER;
			print_matrix(livemap);
		}
		else
			return;
	}
	else if(key == DOWN)
	{
		if(is_next_valid(DOWN, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x + 1][current_y] = PLAYER;
			print_matrix(livemap);
		}
		else
			return;
	}
	else if(key == LEFT)
	{
		if(is_next_valid(LEFT, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x][current_y - 1] = PLAYER;
			print_matrix(livemap);
		}
		else
			return;
	}
	else if(key == RIGHT)
	{
		if(is_next_valid(RIGHT, current_x, current_y, livemap))
		{
			livemap[current_x][current_y] = FLOOR;
			livemap[current_x][current_y + 1] = PLAYER;
			print_matrix(livemap);
		}
		else
			return;
	}
	render(*wdata, &wdata->imgdata, livemap);
}