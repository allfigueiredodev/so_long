SRC = check_and_render.c on_keypress.c destroy_and_close.c set_data.c clone_matrix.c free_map_copy.c print_matrix.c is_trapped.c free_matrix.c file_to_matrix.c map_validations.c map_validations_utils.c so_long_utils.c render.c is_next_valid.c set_current.c controller.c ft_putstr.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
FLAGS = -Wall -Werror -Wextra -g3 -lmlx -lX11 -lXext

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out maps/map.ber
	# valgrind --vgdb=yes --vgdb-error=0 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

all:
	cc $(SRC) $(FLAGS)