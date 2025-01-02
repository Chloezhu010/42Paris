# executable name
NAME = so_long

# path to the minilibx lib
MLX_DIR = ./minilibx-linux

# compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

# main src files
SRC = map.c map_validate.c map_floodfill.c init.c render.c movement.c movement_key.c main_solong.c cleanup.c
OBJ = $(SRC:.c=.o)

# include directory
INC = -I./libft -I$(MLX_DIR)

all: $(NAME)

# make libft first
libft/libft.a:
	make -C libft

# make mlx
$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

$(NAME): $(MLX_DIR)/libmlx.a libft/libft.a $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L./libft -lft $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re