NAME = so_long
LIBFT_PATH = ./libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MAKE = make
TEST_MAP = ./maps/map.ber
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SRC = check_keys.c check_and_render.c on_keypress.c destroy_and_close.c \
set_data.c clone_matrix.c free_map_copy.c is_trapped.c \
free_matrix.c file_to_matrix.c map_validations.c map_validations_utils.c \
so_long_utils.c render.c is_next_valid.c set_current.c controller.c ft_putstr.c \
so_long.c check_flowage.c count_coins.c set_screen_size.c flood_fill.c \
moves_on_display.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./ -Llibft -lft -lmlx -lX11 -lXext

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./so_long $(TEST_MAP)

clean:
	rm -rf $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -rf $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re