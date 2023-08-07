
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

#define SWIDTH 611
#define SHEIGHT 470
#define MAP_PATH "map.ber"
#define SPRITES "sprites_path.txt"

typedef struct s_wdata{
	void	*init; // set by set_window_data >>> mlx_init
	void	*window; // set by window_data >>> mlx_new_window
	char	*title; // set by set_window_data
	int		w;  // set by set_window_data
	int		h;	// set by set_window_data
}	t_wdata;

typedef struct s_imgdata{
	// void	*img; //set by mlx_xpm_file_to_image
	void	*addr; //set by mlx_get_data_addr
	int		bpp; //set by mlx_get_data_addr "32"
	int		line_size; //set by mlx_get_data_addr
	int		endian; //set by mlx_get_data_addr
	void	*sprites[5];
	int		x;
	int		y;
}	t_imgdata;

void print_map(t_wdata wdata, t_imgdata *imgdata, int fd);

#endif