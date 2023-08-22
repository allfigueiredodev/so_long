#include "so_long.h"

int map_validator(t_wdata *wdata, char *filename)
{
	if(!valid_name(filename))
		{
			printf("Error\nWrong file extension\n");
			return(0);
		}
	if(!has_min_size(wdata, wdata->mapinfo.map))
		{
			printf("Error\nMap doesn't have the minimum size\n");
			return(0);
		}
	if(!is_rectangle(wdata->mapinfo.map))
		{
			printf("Error\nMap is not in a rectangle shape\n");
			return(0);
		}
	if(!has_walls(wdata->mapinfo.map))
		{
			printf("Error\nMap has holes on the wall!\n");
			return(0);
		}
	if(!has_all_keys(wdata, wdata->mapinfo.map))
		{
			printf("Error\nLacking of one key or more\n");
			return(0);
		}
	if(!is_trapped(wdata, wdata->mapinfo.map))
		{
			printf("Error\nPlayer is trapped due to, exit or collectables being inaccessible\n");
			return(0);
		}
	return(1);
}