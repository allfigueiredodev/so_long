#include "so_long.h"

void print_matrix(char **matrix)
{
	while(*matrix)
	{
		printf("%s", *matrix);
		matrix++;
	}
}