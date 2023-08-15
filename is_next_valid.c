#include "so_long.h"

int is_next_valid(int key, int x, int y, char **livemap)
{
	int next_x = x;
	int next_y = y;

	if(key == UP)
		next_x = next_x - 1;
	else if(key == DOWN)
		next_x = next_x + 1;
	else if(key == LEFT)
		next_y = next_y - 1;
	else if(key == RIGHT)
		next_y = next_y + 1;

	if(livemap[next_x][next_y] == '1')
		return(0);
	else
		return(1);
}