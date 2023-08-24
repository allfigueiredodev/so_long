#include "so_long.h"

int map_validator(t_wdata *wdata, t_point w_h, char *filename)
{
	if(!valid_name(filename))
		return(0);
	if(!has_min_size(wdata, wdata->mapinfo.map))
		return(0);
	if(!is_rectangle(wdata->mapinfo.map))
		return(0);
	if(!has_walls(wdata->mapinfo.map, w_h))
	{
		ft_printf("Error\nMap has holes on the wall!\n");
		return(0);
	}
	if(!has_all_keys(wdata, wdata->mapinfo.map))
	{
		ft_printf("Error\nLacking keys, or more than one 'E' or 'P' \n");
		return(0);
	}
	if(!is_trapped(wdata, wdata->mapinfo.map))
	{
		ft_printf("Error\nPlayer is trapped due to, exit or collectables being inaccessible\n");
		return(0);
	}
	return(1);
}