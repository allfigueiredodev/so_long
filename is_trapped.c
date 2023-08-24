#include "so_long.h"

int	is_trapped(t_wdata *wdata, char **map)
{
	t_point	size;
	t_point	player;
	char	**map_copy;
	int		i;
	int		j;

	size.x = wdata->mapinfo.s_width / 47;
	size.y = wdata->mapinfo.s_height / 47;
	player.x = 0;
	player.y = 0; 
	i = 0;
	j = 0;
	clone_matrix(&map_copy, map, size.x, size.y);
	set_current(&player.x, &player.y, map_copy);
	flood_fill(map_copy, size, player);
	while (map_copy[i])
	{
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
			{
				free_map_copy(map_copy);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_map_copy(map_copy);
	return(1);
} 