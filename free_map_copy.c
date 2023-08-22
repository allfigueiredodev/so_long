#include "so_long.h"

void free_map_copy(char **map)
{
	int i;
	
	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}