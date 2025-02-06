NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./ft_libft
lib = $(LIBFT_DIR)/libft.a

sources = \
		fdf.c \
		ft_color.c \
		hooks.c \
		draw_shape.c \
		feed_tab.c \
		mouse.c \
		draw.c \
		key.c \
		fill_scale.c \
		rotation.c \
		bresenham.c

object = $(sources:.c=.o)

all: $(NAME) 

$(lib):
	make all -C $(LIBFT_DIR)

$(NAME): $(object) $(lib)
	$(CC) $(CFLAGS) $(object) ./ft_libft/libft.a -lmlx -lXext -lX11  -lm -o $(NAME)

clean:
	rm -rf $(object)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

f: $(object)
	$(CC) $(CFLAGS) $(object) ./ft_libft/libft.a -lmlx -lXext -lX11 -lm -o $(NAME)
	make clean
	clear

.SECONDARY: $(object)
.PHONY: clean fclean re all