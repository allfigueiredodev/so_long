#include "so_long.h"

void clone_matrix(char ***map_copy, char **map, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = y;

	*map_copy = ft_calloc((y + 1), sizeof(char*));
	while(j > 0)
	{
		(*map_copy)[i] = ft_calloc((x + 1), sizeof(char));
		gnl_strlcpy((*map_copy)[i], map[i], x + 1);
		j--;
		i++;
	}
}