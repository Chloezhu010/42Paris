# executable name
NAME = philo

# compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# main src files
SRC_DIR = src
SRC = $(SRC_DIR)/main_test_philo.c \
		$(SRC_DIR)/parse_arg.c \
		$(SRC_DIR)/time.c \
		$(SRC_DIR)/log_msg.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/philo.c \
		$(SRC_DIR)/fork.c \
		$(SRC_DIR)/cleanup.c \
		$(SRC_DIR)/utils.c
OBJ = $(SRC:.c=.o)

# include directory
INC = -I./incl

# rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re