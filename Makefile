all:
	cc game.c -Wall -Werror -Wextra -g3 -lmlx -lX11 -lXext && ./a.out