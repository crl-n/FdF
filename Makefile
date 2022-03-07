# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 14:04:09 by cnysten           #+#    #+#              #
#    Updated: 2022/03/07 15:30:50 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCL = -I/usr/local/include

LIB = -L/usr/local/lib -lmlx

LINK = -framework OpenGL -framework AppKit

SRC = fdf.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) $(INCL)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LINK)

debug: $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(LIB) $(LINK)

clean:
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
