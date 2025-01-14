/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:15:20 by kali              #+#    #+#             */
/*   Updated: 2025/01/13 20:35:27 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../ft_libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# define M_PI 3.14159265358979323846
# define M_WIDTH 1920
# define M_HEIGHT 1080

typedef struct s_coordinates
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	**color;
	int	c;
	int	**tab;
	int	lines;
	int	columns;
}		t_vec;

typedef struct s_scales
{
	int	x;
	int	y;
	int	z;
	int	x_offset;
	int	y_offset;
}		t_scl;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_window;

typedef struct s_all
{
	t_vec		crd;
	t_scl		scale;
	t_window	win;
}				t_all;

// line functions
int		ft_color(const char *s);
char	**ft_read(int fd, char *filename);
void	draw_line(t_all *var);

// hook functions
int		key_hook(int keycode, t_window *window);
int		ft_close(t_window *window);
void	initialisation(t_window *window);
void	hook_manipulation(t_window *window);

#endif