# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 14:04:09 by cnysten           #+#    #+#              #
#    Updated: 2022/03/07 14:59:53 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = /usr/local/lib

LINK = -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -L $(MLX)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX) $(LINK)

debug: $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) -L $(MLX) $(LINK)

clean:
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
