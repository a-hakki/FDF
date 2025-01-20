NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ../ft_libft
MLX_DIR = ../minilibx-linux

lib = $(LIB_DIR)/libft.a
minilibx = $(MLX_DIR)/libmlx_Linux.a


sources = \
		fdf.c \
		ft_color.c \
		hooks.c \
		draw_shape.c \
		feed_tab.c \
		mouse.c \
		draw.c \
		key.c

object = $(sources:.c=.o)

all: $(NAME) 

# libft && minilibx rules
$(lib):
	make all -C $(LIB_DIR) && make -C $(MLX_DIR)

$(NAME): $(object) $(lib)
	$(CC) $(CFLAGS) $(object) ../minilibx-linux/libmlx_Linux.a ../ft_libft/libft.a -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(object)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)

re: fclean all

flush: re clean
	make clean -C $(LIB_DIR)
	rm -rf $(object)
f: $(object)
	$(CC) $(CFLAGS) $(object) ../minilibx-linux/libmlx_Linux.a ../ft_libft/libft.a -lXext -lX11 -lm -lz -o $(NAME)

c: $(object)
	$(CC) $(CFLAGS) $(object) ../minilibx-linux/libmlx_Linux.a ../ft_libft/libft.a -lXext -lX11 -lm -lz -o $(NAME)

.SECONDARY: $(object)
.PHONY: clean fclean re all