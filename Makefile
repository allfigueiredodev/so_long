all:
	cc so_long_aurelie.c -Wall -Werror -Wextra -g3 -lmlx -lX11 -lXext && ./a.out