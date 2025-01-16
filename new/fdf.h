/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:15:20 by kali              #+#    #+#             */
/*   Updated: 2025/01/16 10:14:10 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../ft_libft/libft.h"
# include <math.h>
# define M_PI 3.14159265358979323846
# define M_W 1920
# define M_H 1080

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
	float	x;
	float	y;
	float	z;
	int		x_offset;
	int		y_offset;
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

t_all	*feed_tab(char **file, int lines, t_all	*vars);

// line functions
int		ft_color(const char *s);
void	draw_shape(t_all *var, int flag);
void	fill_scale(t_scl *scale, float x);
void	fill_scale2(t_scl *scale, float x, char c);

// hook functions
int		keyhook(int keycode, t_all *var);
int		ft_close(t_window *window);
void	initialisation(t_window *window, int flag);
void	hook_manipulation(t_all *var);

#endif