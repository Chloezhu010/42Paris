NAME = test_map
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Imlx_linux -lXext -lX11 -lm -lz
# main src files
SRC = main_map.c map.c check_map.c
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
