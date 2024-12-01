# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czhu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 12:13:16 by czhu              #+#    #+#              #
#    Updated: 2024/11/30 12:32:30 by czhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
      ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strdup.c \
      ft_strncmp.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
OBJ = $(SRC: .c = .o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "library $(NAME) created!"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiled $< into $@"

clean:
	@rm -f $(OBJ)
	@echo "object file removed"

fclean: clean
	@rm -f $(NAME)
	@echo "library $(NAME) removed"

re: fclean all
