
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

#define SWIDTH 600
#define SHEIGHT 400
#define SPRITES "sprites_path.txt"
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define ESC 65307
#define WUP 119
#define SDOWN 115
#define ALEFT 97
#define DRIGHT 100
#define FLOOR '0'
#define PLAYER 'P'
#define EXIT 'E'
#define WALL '1'
#define COL 'C'

typedef struct s_mapinfo{
	char **map;
	char *filename;
	int  columns;
	int  rows;
}				t_mapinfo;

typedef struct s_livemap{
	char 		**live_map;
}				t_livemap;

typedef struct s_imgdata{
	void		*addr; //set by mlx_get_data_addr
	void		*sprites[5];
	int 		fd;
	int 		fd2; 
	int			x;
	int			y;
	t_livemap	livemap;
}				t_imgdata;

typedef struct s_game_data{
	int coins;
	int coins_collected;
	int moves;
}				t_game_data;

typedef struct s_wdata{
	void		*init; // set by set_window_data >>> mlx_init
	void		*window; // set by window_data >>> mlx_new_window
	char		*title; // set by set_window_data
	int			w;  // set by set_window_data
	int			h;	// set by set_window_data
	t_mapinfo	mapinfo;
	t_imgdata	imgdata;
	t_game_data game_data;
}				t_wdata;

char 	**print_map(t_wdata *wdata, t_imgdata *imgdata);
void	ft_putstr(char *s);
char 	**live_map(int nrows, int fd2);
void 	controller(int key, t_wdata *wdata);
void 	set_current(int *x, int *y, char **livemap);
int 	is_next_valid(int key, int x, int y, t_wdata *wdata);
// void 	render(t_wdata wdata, t_imgdata *imgdata, char **livemap);
void 	render(t_wdata *wdata, char **map);
void 	print_matrix(char **matrix);
size_t	ft_strlen(const char *s);
int 	on_destroy(t_wdata *wdata);
int 	ft_count_rows(char **matrix);
int 	map_validator(t_wdata *wdata, char *filename);
int 	has_walls(char **map);
int 	has_all_keys(t_wdata *wdata, char **map);
int 	valid_name(char *filename);
int		ft_strcmp(const char *s1, const char *s2);
char 	**file_to_matrix(t_wdata *wdata, char *filename);
int 	ft_count_rows_from_fd(char *filename);
void 	set_game_data(t_wdata *wdata);

#endif