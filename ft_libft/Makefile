NAME = libft.a
source =  \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c \
		ft_split.c \
		ft_strdup.c \
		ft_arrlen.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		printfd.c \
		ft_checknext.c \
		ft_isvalid.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putadrs.c \
		ft_putadrsx.c \
		ft_putnum.c \
		ft_putunum.c \
		ft_puthex.c \
		get_next_line.c \
		ft_file_form.c \
		int_free.c \
		ft_free.c \
		ft_read.c

object = $(source:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(object)
	ar rc $(NAME) $(object)

clean:
	rm -f $(object)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(object)

.PHONY: clean
