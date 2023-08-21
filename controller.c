#include "so_long.h"

int move_up(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char **livemap;

	livemap = wdata->imgdata.livemap.live_map;
	if(is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if(wdata->game_data.coins_collected == wdata->game_data.coins && livemap[cur_x - 1][cur_y] == EXIT)
			on_destroy(wdata);
		livemap[cur_x][cur_y] = FLOOR;
		livemap[cur_x - 1][cur_y] = PLAYER;
		wdata->game_data.moves++;
		return(1);
	}
	else
		return(0);
}

int move_down(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char **livemap;
	
	livemap = wdata->imgdata.livemap.live_map;
	if(is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if(wdata->game_data.coins_collected == wdata->game_data.coins && livemap[cur_x + 1][cur_y] == EXIT)
			on_destroy(wdata);
		livemap[cur_x][cur_y] = FLOOR;
		livemap[cur_x + 1][cur_y] = PLAYER;
		wdata->game_data.moves++;
		return(1);
	}
	else
		return(0);
}

int move_left(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char **livemap;
	
	livemap = wdata->imgdata.livemap.live_map;
	if(is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if(wdata->game_data.coins_collected == wdata->game_data.coins && livemap[cur_x][cur_y - 1] == EXIT)
			on_destroy(wdata);
		livemap[cur_x][cur_y] = FLOOR;
		livemap[cur_x][cur_y - 1] = PLAYER;
		wdata->game_data.moves++;
		return(1);
	}
	else
		return(0);
}

int move_right(int direction, int cur_x, int cur_y, t_wdata *wdata)
{
	char **livemap;
	
	livemap = wdata->imgdata.livemap.live_map;
	if(is_next_valid(direction, cur_x, cur_y, wdata))
	{
		if(wdata->game_data.coins_collected == wdata->game_data.coins && livemap[cur_x][cur_y + 1] == EXIT)
			on_destroy(wdata);
		livemap[cur_x][cur_y] = FLOOR;
		livemap[cur_x][cur_y + 1] = PLAYER;
		wdata->game_data.moves++;
		return(1);
	}
	else
		return(0);
}

int controller(int key, t_wdata *wdata)
{
	int current_x = 0;
	int current_y = 0;
	char **livemap = wdata->imgdata.livemap.live_map;

	set_current(&current_x, &current_y, livemap);
	if(key == UP || key == WUP)
	{
		if(move_up(UP, current_x, current_y, wdata))
		{
			render(wdata, livemap);
			return(1);
		}
	}
	else if(key == DOWN || key == SDOWN)
	{
		if(move_down(DOWN, current_x, current_y, wdata))
		{
			render(wdata, livemap);
			return(1);
		}
	}
	else if(key == LEFT || key == ALEFT)
	{
		if(move_left(LEFT, current_x, current_y, wdata))
		{
			render(wdata, livemap);
			return(1);
		}
	}
	else if(key == RIGHT || key == DRIGHT)
	{
		if(move_right(RIGHT, current_x, current_y, wdata))
		{
			render(wdata, livemap);
			return(1);
		}
	}
	return(0);
}