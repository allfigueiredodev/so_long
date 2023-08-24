#include "so_long.h"

int on_keypress(int keysym, t_wdata *wdata)
{
	if(keysym == UP || keysym == DOWN || keysym == LEFT || keysym == RIGHT
	|| keysym == WUP || keysym == SDOWN || keysym == ALEFT || keysym == DRIGHT)
	{
		if(controller(keysym, wdata))
			ft_printf("Total moves: %d\n", wdata->game_data.moves);
	}
	else if(keysym == ESC)
		on_destroy(wdata);	
	return (0);
}