/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:22:02 by aperis-p          #+#    #+#             */
/*   Updated: 2023/07/20 16:01:39 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include 	<mlx.h>
#include <stdint.h>

#define WIN_W 800
#define WIN_H 600
#define MLX_ERROR 1

typedef struct	s_data {
	void 	*mlx;
	void 	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
	
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    return (red << 16 | green << 8 | blue);
}
	
int main(void)
{
	t_data img;
	
	img.mlx = mlx_init();
	if (img.mlx == NULL)
        return (MLX_ERROR);
	img.mlx_win = mlx_new_window(img.mlx, WIN_W, WIN_H, "so_long");
	if (img.mlx_win == NULL)
	{
		free(img.mlx_win);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(img.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	mlx_destroy_window(img.mlx, img.mlx_win);
    mlx_destroy_display(img.mlx);
    free(img.mlx);
}