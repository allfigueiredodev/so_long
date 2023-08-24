#include "so_long.h"

void set_current(int *x, int *y, char **livemap)
{
	int i = *y;
	int j = *x;

	while(livemap[i][j] && livemap[i][j != 'P'])
	{
		while(livemap[i][j] && livemap[i][j] != 'P')
			j++;
		if(livemap[i][j] != 'P')
		{
			i++;
			j = 0;
		}
		else
			break;
	}
	*x = j;
	*y = i;
}
