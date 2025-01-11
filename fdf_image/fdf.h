#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "../ft_libft/libft.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846
#define M_WIDTH 1920
#define M_HEIGHT 1080

typedef struct s_coordinates
{
    int X0;
    int Y0;
    int X1;
    int Y1;
    int **color;
    int c;
    int **tab;
    int lines;
    int columns;
}               t_vec;


typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    float     x;
}				t_vars;

int     ft_color(const char *s);

#endif