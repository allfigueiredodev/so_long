#include "so_long.h"

void print_map(t_wdata wdata, t_imgdata *imgdata, int fd)
{	
	int width = 0;
	int height = 0;
	char *line;
	char *line_tmp;
	int i;
 
	line = get_next_line(fd);
	line_tmp = line;
	i = 0;
	while (line_tmp)
	{
		while(*line_tmp && *line_tmp != '\n')
		{
			if(*line_tmp == '1')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[0], width, height);
			else if (*line_tmp == '0')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[1], width, height);
			else if (*line_tmp == 'P')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[2], width, height);
			else if (*line_tmp == 'E')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[3], width, height);
			else if (*line_tmp == 'C')
				mlx_put_image_to_window(wdata.init, wdata.window, imgdata->sprites[4], width, height);
			width += 47;
			line_tmp++;
		}	
		height += 47;
		width = 0;
		if(line_tmp)
			free(line);
		line = get_next_line(fd);
		line_tmp = line;
	}
}