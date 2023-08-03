SRC = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
FLAGS = -Wall -Werror -Wextra -g3 -lmlx -lX11 -lXext

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

all:
	cc $(SRC) $(FLAGS)