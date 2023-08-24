NAME = so_long.a
LIBFT_PATH = ./libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MAKE = make
AR = ar rcs
RL = ranlib
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SRC = map_wall_validations.c check_and_render.c on_keypress.c destroy_and_close.c \
set_data.c clone_matrix.c free_map_copy.c print_matrix.c is_trapped.c \
free_matrix.c file_to_matrix.c map_validations.c map_validations_utils.c \
so_long_utils.c render.c is_next_valid.c set_current.c controller.c ft_putstr.c \
so_long.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./ -Llibft -lft -lmlx -lX11 -lXext

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

clean:
	rm -rf $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -rf $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re