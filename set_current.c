#include "so_long.h"

void set_current(int *x, int *y, char **livemap)
{
	int i = *x;
	int j = *y;

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
	*x = i;
	*y = j;
}
