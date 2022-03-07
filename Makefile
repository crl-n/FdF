# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 14:04:09 by cnysten           #+#    #+#              #
#    Updated: 2022/03/07 21:25:58 by carlnysten       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ifneq ("$(wildcard /usr/local/lib/libmlx.a)", "")
LIB = -L/usr/local/lib -lmlx
else
LIB = -L/usr/X11/lib -lmlx
endif

ifneq ("$(wildcard /usr/local/include/mlx.h)", "")
INCL = -I/usr/local/include
else
INCL = -I/usr/X11/include
endif

LINK = -framework OpenGL -framework AppKit

SRC = fdf.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) $(INCL)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LINK)

home: $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC) $(INCL)

debug: $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(LIB) $(LINK)

clean:
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
