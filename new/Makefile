NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
sources = \
		fdf.c \
		ft_color.c \
		ft_read.c \
		hooks.c \
		draw_line.c

object = $(sources:.c=.o)

minilibx = $(shell cd ../minilibx-linux/ && make && cp libmlx_Linux.a ../new)
ifeq ($(minilibx),FreeBSD)
	CC = clang
endif

libft = $(shell cd ../ft_libft/ && make && cp libft.a ../new)
ifeq ($(libft),FreeBSD)
	CC = clang
endif

all: $(NAME)

$(NAME): $(object)
	$(CC) $(CFLAGS) $(object) libmlx_Linux.a libft.a -lXext -lX11 -lm -lz -g -o $(NAME)

clean:
	rm -f $(object)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(object)

.PHONY: clean