#include "so_long.h"
#include <string.h>

int valid_name(char *filename)
{
	int lenght;

	lenght = ft_strlen(filename);
	if(lenght < 4)
		return(0);
	if((filename + (lenght - 4)) != ".ber")
		return(0);
	return(1);
}

int is_rectangle(char **map)
{
	int x;
	int y;

	x = ft_strlen(map[0]);
	y = ft_count_rows(map);

	if (x == y)
		return(0);
	return(1);
}

int has_walls(char **map)
{
	int lenght;
	int rows;
	int i;
	int j;

	lenght = strlen(map[0]);
	rows = ft_count_rows(map);
	i = 0;
	j = 0;
	while(map[0][i])
	{
		if(map[0][i] != '1')
			return(0);
		i++;
	}
	i = 0;
	while(map[rows - 1][i])
	{
		if(map[rows - 1][i] != '1')
			return(0);
		i++;
	}
	i = 1;
	while(i < rows)
	{
		if(map[i][j] == '1' && map[i][lenght - 1] == '1')
			i++;
		else
			return(0);
	}
	return(1);	
}

int has_min_size(char **map)
{
	int x;
	int y;

	x = ft_strlen(map[0]);
	y = ft_count_rows(map);

	if ((x > 3 && y > 5) || (y > 3 && x > 5))
		return(1);
	else
		return(0);
}

int has_all_keys(char **map)
{
	int keys;
	int i;
	int j;
	
	keys = 0b00000;
	i = 0;
	j = 0;

	while(map[i])
	{
		while(map[i][j])
		{
			if(map[i][j] == '1')
				keys |= (1 << 4);
			else if(map[i][j] == '0')
				keys |= (1 << 3);
			else if(map[i][j] == 'P')
				keys |= (1 << 2);
			else if(map[i][j] == 'E')
				keys |= (1 << 1);
			else if(map[i][j] == 'C')
				keys |= 1;
			else
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if(keys == 31 )
		return(1);
	return(0);
}

int map_validator(t_wdata wdata, char *filename)
{
	if(!valid_name)
		return(0);
	if(!is_rectangle)
		return(0);
	if(!has_walls)
		return(0);
	if(!has_min_size)
		return(0);
	return(1);
}

// file has to end with .ber - OK
// needs to be a rectangle - OK
// the map should have '1' 'walls' around the entire map - OK
// also need a min size "3 x 5 || 5 x 3" - OK
// the map cannot have any character besides "1,0,E,C,P" - OK