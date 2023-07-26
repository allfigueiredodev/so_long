#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

#define WIDTH_STD 352 / 2
#define HEIGHT_STD 417 / 4

typedef struct s_machine{
	void	*win;
	void	*display;
	char	*title; // set
	int		w;  // set
	int		h;	// set
	int		x;
	int		y;
}	t_machine;

typedef struct s_img{
	void	*img;
	void	*addr;
	int		bpp;
	int		x;
	int		y;
	int		w;
	int		h;
}	t_img;

void	mlx_machine_set(t_machine *machine, char *title, int w, int h)
{
	machine->title = title;
	machine->w = w;
	machine->h = h;
	// machine->win = NULL;
	// machine->display = NULL;
}

void	mlx_plugin_init(t_machine *machine)
{
	machine->display = mlx_init();
	if (!machine->display)
	{
		printf("mlx_plugin_init: error at mlx initialization\n");
		return ;
	}
	machine->win = mlx_new_window(machine->display, machine->w, machine->h, machine->title);
	if (!machine->win)
	{
		printf("mlx_plugin_init: error trying to create a window\n");
		return ;
	}
}

void	mlx_plugin_img(t_machine *machine, t_img *set, char *path)
{
	if (!machine || !set || !path)
		return ;
	set->img = mlx_xpm_file_to_image(machine->display, path, &set->w, &set->h);
	printf("%i %i\n", set->w, set->h);
	if (set->img)
	{
		set->addr = mlx_get_data_addr(set->img, &set->bpp, &set->w, &set->h);
	}
}

void	mlx_plugin_draw(t_machine *machine, t_img *set)
{
	if (!machine || !machine->display || !machine->win || !set || !set->img)
	{
		printf("mlx_plugin_draw: error\n");
		return ;
	}
	mlx_put_image_to_window(machine->display, machine->win, set->img, set->x, set->y);
}

void	mlx_plugin_destroy(t_machine *machine)
{
	if (!machine)
		return ;
	if (machine->win && machine->display)
		mlx_destroy_window(machine->display, machine->win);
	if (machine->display)
		mlx_destroy_display(machine->display);
}

int	main(void)
{
	t_machine	*m;
	t_img		*i;

	m = malloc(sizeof(t_machine));
	if(!m)
		return (0);
	i = malloc(sizeof(t_img));
	if(!i)
		return (0);
	mlx_machine_set(m, "so long", WIDTH_STD, HEIGHT_STD);
	mlx_plugin_init(m);
	mlx_plugin_img(m, i, "assets/floor.xpm");
	mlx_plugin_draw(m, i);
	mlx_loop(m->display);
	mlx_plugin_destroy(m);
	return (0);
}