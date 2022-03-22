.SILENT: clean, fclean
.PHONY: all, clean, fclean, re

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifneq ("$(wildcard /usr/local/lib/libmlx.a)", "")
LIB = -L/usr/local/lib -lmlx
else
LIB = -L/usr/X11/lib -lmlx
endif

LIB += -L./libft/ -lft

ifneq ("$(wildcard /usr/local/include/mlx.h)", "")
INCL = -I/usr/local/include
else
INCL = -I/usr/X11/include
endif

INCL += -I./libft

FW = -framework OpenGL -framework AppKit

SRC = control.c draw.c draw_line.c fdf.c line.c parse.c parse_util.c projection.c

OBJ = $(SRC:%.c=%.o)

#OBJ += ./libft/ft_putstr.o ./libft/ft_strlen.o ./libft/get_next_line.o

all: $(NAME)

$(OBJ): $(SRC)
	make -C ./libft
	$(CC) $(CFLAGS) -c $(SRC) $(INCL) -g

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(FW)

home: $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC) $(INCL)

debug: $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(LIB) $(FW)

clean:
	-/bin/rm $(OBJ)
	make -C ./libft clean

fclean: clean
	-/bin/rm $(NAME)
	make -C ./libft fclean

re: fclean all
