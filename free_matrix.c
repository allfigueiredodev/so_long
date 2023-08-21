#include "so_long.h"

void free_matrix(t_wdata *wdata)
{
	int i;
	
	i = 0;
	while(wdata->mapinfo.map[i])
	{
		free(wdata->mapinfo.map[i]);
		i++;
	}
	free(wdata->mapinfo.map);
}