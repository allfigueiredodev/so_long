/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:06:21 by aperis-p          #+#    #+#             */
/*   Updated: 2023/08/26 13:00:26 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <stdint.h>
# include <errno.h>

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define WUP 119
# define SDOWN 115
# define ALEFT 97
# define DRIGHT 100
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define WALL '1'
# define COL 'C'

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_mapinfo{
	char	**map;
	char	*filename;
	int		s_width;
	int		s_height;
}				t_mapinfo;

typedef struct s_livemap{
	char		**live_map;
}				t_livemap;

typedef struct s_imgdata{
	void		*sprites[5];
	int			fd;
	int			x;
	int			y;
	t_livemap	livemap;
}				t_imgdata;

typedef struct s_game_data{
	int	coins;
	int	coins_collected;
	int	moves;
}				t_game_data;

typedef struct s_wdata{
	void		*init;
	void		*window;
	char		*title;
	int			w;
	int			h;	
	t_mapinfo	mapinfo;
	t_imgdata	imgdata;
	t_game_data	game_data;
}				t_wdata;

void	ft_putstr(char *s);
int		controller(int key, t_wdata *wdata);
void	set_current(int *x, int *y, char **livemap);
int		is_next_valid(int key, int x, int y, t_wdata *wdata);
void	render(t_wdata *wdata, char **map);
void	print_matrix(char **matrix);
size_t	ft_strlen(const char *s);
int		on_destroy(t_wdata *wdata);
int		has_all_keys(char **map);
int		valid_name(char *filename);
int		ft_strcmp(const char *s1, const char *s2);
char	**file_to_matrix(t_wdata *wdata, char *filename);
int		ft_count_rows_from_fd(char *filename);
void	set_game_data(t_wdata *wdata, char **map);
void	free_matrix(t_wdata *wdata);
void	flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point cur, char to_fill);
int		is_rectangle(char **map);
int		has_min_size(t_wdata *wdata, char **map);
int		is_trapped(t_wdata *wdata, char **map);
void	free_map_copy(char **map);
void	*ft_calloc(size_t nmemb, size_t size);
void	clone_matrix(char ***map_copy, char **map, int x, int y);
void	set_window_data(t_wdata *wdata, char *title);
void	set_image_data(t_wdata *wdata, t_imgdata *imgdata, char *filename);
int		has_walls(char **map, t_point w_h);
int		map_validator(t_wdata *wdata, t_point w_h, char *filename);
int		ft_count_rows(char **matrix);
int		img_destroy(t_wdata *wdata, t_imgdata *imgdata);
int		on_destroy(t_wdata *wdata);
int		on_keypress(int keysym, t_wdata *wdata);
int		check_and_render_up(int direction, int cur_x,
			int cur_y, t_wdata *wdata);
int		check_and_render_down(int direction, int cur_x,
			int cur_y, t_wdata *wdata);
int		check_and_render_left(int direction, int cur_x,
			int cur_y, t_wdata *wdata);
int		check_and_render_right(int direction, int cur_x,
			int cur_y, t_wdata *wdata);
int		move_up(int direction, int cur_x, int cur_y, t_wdata *wdata);
int		move_down(int direction, int cur_x, int cur_y, t_wdata *wdata);
int		move_left(int direction, int cur_x, int cur_y, t_wdata *wdata);
int		move_right(int direction, int cur_x, int cur_y, t_wdata *wdata);
char	**get_matrix(int rows, int fd);
int		check_keys(int i, int j, int keys, char **map);
int		check_flowage(char **map_copy);
void	count_coins(t_wdata *wdata, char **map);
void	set_screen_size(t_point *w_h, t_wdata wdata);
void	get_first_c(int *x, int *y, char **livemap);
int		check_fill_p(char **map_copy, t_point size);
int		check_fill_c(char **map_copy, t_point size);
void	fill_from_p(char **map, t_point size, t_point cur, char to_fill);
void	fill_from_c(char **map, t_point size, t_point cur, char to_fill);
int		check_flowage_p(char **map_copy);
int		check_flowage_c(char **map_copy);
void	flood_fill_p(char **map, t_point size, t_point start);
void	flood_fill_c(char **map, t_point size, t_point start);
void	moves_on_display(t_wdata *wdata);

#endif