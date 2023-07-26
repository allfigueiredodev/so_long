/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_aurelie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:20:39 by aperis-p          #+#    #+#             */
/*   Updated: 2023/07/26 15:21:37 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define TRANSPARENT 0x00000000
#define FILE_PATH "./assets/floor.xpm"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	int 	width;
	int 	height;
}	t_img;

typedef struct s_sprite
{
	void	*mlx_img;
	char 	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_sprite	sprites;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	int i = 0;
	int j = 0;
	int k = -1;
	
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	while(j < WINDOW_HEIGHT)
	{
		k++;
		i = 0;
		if(k % 2 == 0)
		{
			while(i < WINDOW_WIDTH)
			{	
				if(j % 2 == 1)
				{
					render_rect(&data->img, (t_rect){i, j, 60, 60, GREEN_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
					render_rect(&data->img, (t_rect){i, j, 60, 60, WHITE_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
				}
				else
				{
					render_rect(&data->img, (t_rect){i, j, 60, 60, WHITE_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
					render_rect(&data->img, (t_rect){i, j, 60, 60, GREEN_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
				}
			}
		}
		else
		{
			while(i < WINDOW_WIDTH)
			{
				if(j % 2 == 0)
				{
					render_rect(&data->img, (t_rect){i, j, 60, 60, RED_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
					render_rect(&data->img, (t_rect){i, j, 60, 60, WHITE_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
				}
				else
				{
					render_rect(&data->img, (t_rect){i, j, 60, 60, WHITE_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
					render_rect(&data->img, (t_rect){i, j, 60, 60, RED_PIXEL});
					i = i + 2 * (WINDOW_HEIGHT / 10);
				}
			}
		}
		j = j + (WINDOW_HEIGHT / 5);
	}

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

// int	render(t_data *data)
// {
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.mlx_img, 0, 0);
// 	return(0);
// }

int	main(void)
{
	t_data	data;
	// t_sprites sprites;

	data.mlx_ptr = mlx_init(); //Initializes the MLX library. Must be called before ANY other function. Will return NULL if initialization failed.
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long"); //Creates a new window instance. It will return a window instance pointer.
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	/* Setup hooks */ 
	
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img = mlx_ptr = mlx_xpm_file_to_image(data.img.mlx_img, FILE_PATH, &data.img.width, &data.img.height);
	
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &render, &data); // Hook into the loop.
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); // Hook into the keypress event.

	mlx_loop(data.mlx_ptr); //Loop over the given MLX pointer. Each hook that was registered prior to this will be called accordingly by order of registration.

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img); // Destroys an image instance accordingly.
	mlx_destroy_display(data.mlx_ptr); // Destroys the display instance.
	free(data.mlx_ptr);
}