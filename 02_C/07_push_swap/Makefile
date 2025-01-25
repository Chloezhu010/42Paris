# executable name
NAME = push_swap

# compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# main src files
SRC_DIR = src
SRC = $(SRC_DIR)/stack_init.c \
		$(SRC_DIR)/stack_utils.c \
		$(SRC_DIR)/error.c \
		$(SRC_DIR)/swap.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/rev_rotate.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/init_node_a.c \
		$(SRC_DIR)/init_node_b.c \
		$(SRC_DIR)/sort_three.c \
		$(SRC_DIR)/sort_stack.c \
		$(SRC_DIR)/main.c
OBJ = $(SRC:.c=.o)

# include directory
INC = -I./incl -I$(SRC_DIR)/libft

# libft directory
LIBFT_DIR = $(SRC_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# rules
all: $(NAME)

# build libft first
$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re