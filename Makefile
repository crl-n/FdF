.SILENT: clean, fclean
.PHONY: all, clean, fclean, re

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

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

SRC = allocators.c color.c control.c control_utils.c draw.c draw_line.c \
	  fdf.c image.c menu.c parse.c projection.c \
	  rotate.c utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ): $(SRC)
	@make -C ./libft
	$(CC) $(CFLAGS) -c $(SRC) $(INCL)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(FW)

clean:
	-/bin/rm $(OBJ)
	@make -C ./libft clean

fclean: clean
	-/bin/rm $(NAME)
	@make -C ./libft fclean

re: fclean all
