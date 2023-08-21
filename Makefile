SRC = set_game_data.c file_to_matrix.c file_checker.c so_long_utils.c print_matrix.c render.c is_next_valid.c set_current.c live_map.c controller.c ft_putstr.c so_long.c print_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
FLAGS = -Wall -Werror -Wextra -g3 -lmlx -lX11 -lXext

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out map.ber
	# valgrind --vgdb=yes --vgdb-error=0 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

all:
	cc $(SRC) $(FLAGS)