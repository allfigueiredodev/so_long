#include "so_long.h"

int main(void)
{
	t_wdata wdata;
	t_point size = {13, 6};
	t_point start = {4, 2};
	char **test;
	char **test_temp;

	test = file_to_matrix(&wdata, "map_player_blocked.ber");
	test_temp = test;
	print_matrix(test);
	flood_fill(test_temp, size, start);
	printf("\n");
	print_matrix(test_temp);
}