/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:23:17 by ahakki            #+#    #+#             */
/*   Updated: 2024/11/13 14:00:32 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// math functions
int		ft_abs(int a);
int	ft_max(int a, int b);

// ft_is functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);

// memory functions
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t num, size_t size);
void	*int_free(char *format, ...);
char	*ft_free(char *format, ...);

// string functions
size_t	ft_strlen(const char *str);
size_t	ft_arrlen(char **arr);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *str, const char *sub, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// file descript functions
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);
int		ft_file_form(char *name, char *form);
char	**ft_read(int fd, char *filename);

// linked list functions
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

// printfd functions
int		printfd(int fd, const char *s, ...);
int		ft_checknext(int fd, const char c, va_list arg);	
int		ft_isvalid(const char c);
int		ft_putchar(int fd, char c);
int		ft_putstr(int fd, const char *s);
int		ft_putadrs(int fd, void *p);
int		ft_putadrsx(int fd, size_t a, char c);
int		ft_putnum(int fd, int n);
int		ft_putunum(int fd, unsigned int n);
int		ft_puthex(int fd, unsigned int a, char c);

#endif
