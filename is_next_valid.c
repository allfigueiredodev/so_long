#include "so_long.h"

int is_next_valid(int key, int x, int y, char **livemap)
{
	int next_x = x;
	int next_y = y;

	if(key == UP || key == WUP)
		next_x = next_x - 1;
	else if(key == DOWN || key == SDOWN)
		next_x = next_x + 1;
	else if(key == LEFT || key == ALEFT)
		next_y = next_y - 1;
	else if(key == RIGHT || key == DRIGHT)
		next_y = next_y + 1;

	if(livemap[next_x][next_y] == WALL)
		return(0);
	else
		return(1);
}