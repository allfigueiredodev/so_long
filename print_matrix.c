#include "so_long.h"

void print_matrix(char **matrix)
{
	while(*matrix)
	{
		ft_printf("%s\n", *matrix);
		matrix++;
	}
}