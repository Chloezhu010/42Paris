# executable name
NAME = philo

# compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# main src files
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/thread.c \
		$(SRC_DIR)/philo_routine.c \
		$(SRC_DIR)/monitor.c \
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