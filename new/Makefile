NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SOURCES = \
		fdf.c \
		ft_color.c \
		ft_read.c \
		hooks.c \
		draw_line.c

OBJECTS = $(SOURCES:.c=.o)

MINILIBX_PATH = ../minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a

LIBFT_PATH = ../ft_libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MINILIBX):
	make -C $(MINILIBX_PATH)
	cp $(MINILIBX) .

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_PATH) clean || echo "No clean rule in $(LIBFT_PATH)"
	make -C $(MINILIBX_PATH) clean || echo "No clean rule in $(MINILIBX_PATH)"

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean || echo "No fclean rule in $(LIBFT_PATH)"
	make -C $(MINILIBX_PATH) clean || echo "No clean rule in $(MINILIBX_PATH)"
	rm -f libmlx_Linux.a

re: fclean all


.PHONY: clean
