#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

// #define WIDTH_STD 352
// #define HEIGHT_STD 417
#define WIDTH_STD 600
#define HEIGHT_STD 480
#define PATH "assets/one_tile_floor.xpm"

typedef struct s_machine{
	void	*win; // set by mlx_init
	void	*display; // set by mlx_new_window
	char	*title; // set by mlx_machine_set
	int		w;  // set by mlx_machine_set
	int		h;	// set by mlx_machine_set
}	t_machine;

typedef struct s_img{
	void	*img; //set by mlx_xpm_file_to_image
	void	*addr; //set by mlx_get_data_addr
	int		bpp; //set by mlx_get_data_addr "32"
	int		x; 
	int		y; 
	int		w; //set by mlx_get_data_addr
	int		h; //set by mlx_get_data_addr
}	t_img;

void	mlx_machine_set(t_machine *machine, char *title, int w, int h)
{
	machine->title = title;
	machine->w = w;
	machine->h = h;
}

void	mlx_plugin_init(t_machine *machine)
{
	machine->win = mlx_init();
	if (!machine->win)
	{
		printf("mlx_plugin_init: error at mlx initialization\n");
		return ;
	}
	machine->display = mlx_new_window(machine->win, machine->w, machine->h, machine->title);
	if (!machine->display)
	{
		printf("mlx_plugin_init: error trying to create a window\n");
		return ;
	}}

void	mlx_plugin_img(t_machine *machine, t_img *img, char *path)
{
	if (!machine || !img || !path)
		return ;
	img->img = mlx_xpm_file_to_image(machine->win, path, &img->w, &img->h);
	if (img->img)
	{
		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->w, &img->h);
	}
}

int	mlx_plugin_draw(t_machine *machine, t_img *img)
{
	if (!machine || !machine->win || !machine->display || !img || !img->img)
	{
		printf("mlx_plugin_draw: error\n");
		return (1);
	}
	mlx_put_image_to_window(machine->win, machine->display, img->img, img->x, img->y);
	return (0);
}

void	mlx_plugin_destroy(t_machine *machine, t_img *img)
{
	if (!machine)
		return ;
	mlx_destroy_image(machine->win, img->img);
	if (machine->display && machine->win)
		mlx_destroy_window(machine->win, machine->display);
	if (machine->win)
		mlx_destroy_display(machine->win);
	
}

int	handle_keypress(int keysym, t_machine *m)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(m->win);
		mlx_destroy_window(m->win, m->display);
		m->win = NULL;
	}
	return (0);
}

int	main(void)
{
	t_machine	m;
	t_img		*img;

	// m = malloc(sizeof(t_machine));
	// if(!&m)
	// 	return (0);
	img = malloc(sizeof(t_img));
	if(!img)
		return (0);
	mlx_machine_set(&m, "so long", WIDTH_STD, HEIGHT_STD);
	mlx_plugin_init(&m);
	mlx_plugin_img(&m, img, PATH);
	mlx_plugin_draw(&m, img);
	// img->x = 100;
	// img->y = 100;
	// mlx_plugin_draw(&m, img);
	// mlx_loop_hook(m.win, &mlx_plugin_draw, &m);
	mlx_hook(m.display, KeyPress, KeyPressMask, &handle_keypress, &m);
	mlx_loop(m.win);
	// mlx_plugin_destroy(&m, img);
	// mlx_destroy_image(m.win, img->addr); // Destroys an image instance accordingly.
	// mlx_destroy_display(m.win); // Destroys the display instance.
	free(m.win);
	free(img);
	return (0);
}