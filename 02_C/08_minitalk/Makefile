# executable name
SERVER = server
CLIENT = client

# compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# directories
SRC_DIR = src/
INCL_DIR = incl/
LIBFT_DIR = src/libft/

# src files
SERVER_SRC = $(SRC_DIR)server.c
CLIENT_SRC = $(SRC_DIR)client.c

# object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# libft
LIBFT = $(LIBFT_DIR)libft.a

# incl. path
INCLUDES = -I$(INCL_DIR) -I$(LIBFT_DIR)

all: $(LIBFT) $(CLIENT) $(SERVER)

# build libft first
$(LIBFT):
	make -C $(LIBFT_DIR)

# build server
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

# build client
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re