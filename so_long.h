
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define SWIDTH 600
#define SHEIGHT 480
#define PATH "assets/one_tile_floor.xpm"

typedef struct s_wdata{
	void	*init; // set by set_window_data >>> mlx_init
	void	*window; // set by window_data >>> mlx_new_window
	char	*title; // set by set_window_data
	int		w;  // set by set_window_data
	int		h;	// set by set_window_data
}	t_wdata;

typedef struct s_imgdata{
	void	*img; //set by mlx_xpm_file_to_image
	void	*addr; //set by mlx_get_data_addr
	int		bpp; //set by mlx_get_data_addr "32"
	int		line_size; //set by mlx_get_data_addr
	int		endian; //set by mlx_get_data_addr
	int		x; 
	int		y; 
}	t_imgdata;

#endif