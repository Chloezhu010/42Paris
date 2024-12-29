# executable name
NAME = test_init

# path to the minilibx lib
MLX_DIR = ./minilibx

# compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# main src files
SRC = map.c map_utils.c init.c main_init.c
OBJ = $(SRC:.c=.o)

# include directory
INC = -I./libft

all: $(NAME)

# make libft first
libft/libft.a:
	make -C libft

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(OBJ) libft/libft.a $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

%.o:$.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
