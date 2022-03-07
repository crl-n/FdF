# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 14:04:09 by cnysten           #+#    #+#              #
#    Updated: 2022/03/07 14:20:43 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = fdf.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) 

debug: $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) 

clean:
	/bin/rm $(OBJ)

flcean: clean
	/bin/rm $(NAME)

re: fclean all
