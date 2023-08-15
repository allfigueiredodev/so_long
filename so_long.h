
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
#include <stdint.h>

#define SWIDTH 611
#define SHEIGHT 470
#define MAP_PATH "map.ber"
#define SPRITES "sprites_path.txt"
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define FLOOR '0'
#define PLAYER 'P'

typedef struct s_livemap{
	char 		**live_map;
}				t_livemap;

typedef struct s_imgdata{
	// void	*img; //set by mlx_xpm_file_to_image
	void		*addr; //set by mlx_get_data_addr
	// int		bpp; //set by mlx_get_data_addr "32"
	// int		line_size; //set by mlx_get_data_addr
	// int		endian; //set by mlx_get_data_addr
	void		*sprites[5];
	int			x;
	int			y;
	t_livemap	livemap;
}				t_imgdata;

typedef struct s_wdata{
	void		*init; // set by set_window_data >>> mlx_init
	void		*window; // set by window_data >>> mlx_new_window
	char		*title; // set by set_window_data
	int			w;  // set by set_window_data
	int			h;	// set by set_window_data
	t_imgdata	imgdata;
}				t_wdata;

char 	**print_map(t_wdata wdata, t_imgdata *imgdata, int fd, int fd2);
// void 	print_map(t_wdata wdata, t_imgdata *imgdata, int fd, int fd2);
void	ft_putstr(char *s);
char 	**live_map(int nrows, int fd2);
// void 	controller(int key, char **livemap);
void 	controller(int key, t_wdata *wdata);
void 	set_current(int *x, int *y, char **livemap);
int 	is_next_valid(int key, int x, int y, char **livemap);
void 	render(t_wdata wdata, t_imgdata *imgdata, char **livemap);
void 	print_matrix(char **matrix);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);


#endif