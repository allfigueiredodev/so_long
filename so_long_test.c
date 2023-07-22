/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:38:18 by aperis-p          #+#    #+#             */
/*   Updated: 2023/07/22 20:12:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define MAP_PATH "./assets/AnyConv.com__TilesetFloor.xpm"
// #define MAP_PATH_PNG "./assets/NinjaAdventure/Backgrounds/Tilesets/TilesetFloor.png"
 
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *mlx_img;
	int width;
	int height;

} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}
 
int main(void)
{
	t_data data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1024, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.mlx_img = mlx_new_image(data.mlx_ptr, 1920, 1024);
	mlx_xpm_file_to_image(data.mlx_ptr, MAP_PATH, &data.width, &data.height);
	// mlx_png_file_to_image(data.mlx_ptr, MAP_PATH_PNG, data.width, data.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.mlx_img, 0, 0);
	 
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}