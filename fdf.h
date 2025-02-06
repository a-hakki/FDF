/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:15:20 by kali              #+#    #+#             */
/*   Updated: 2025/02/06 09:00:19 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./ft_libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>
# define M_PI 3.14159265358979323846

#if !defined(M_W)
# define M_W 1920
#endif

#if !defined(M_H)
# define M_H 1080
#endif

typedef struct s_coordinates
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	**color;
	int	c;
	int	c_end;
	int	**tab;
	int	lines;
	int	columns;
}			t_vec;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	r2;
	int	g2;
	int	b2;
	int	r_interp;
	int	g_interp;
	int	b_interp;
}			t_color;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}			t_line;

typedef struct s_scales
{
	float	x;
	float	y;
	float	z;
	int		x_offset;
	int		y_offset;
	int		x_ms;
	int		y_ms;
	int		flag;
	int		mouse_pressed;
	int		projection;
	int		rot_direction;
}		t_scl;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_window;

typedef struct s_rot
{
	float		x0;
	float		y0;
	float		z0;
	float		x1;
	float		y1;
	float		z1;
}				t_rot;

typedef struct s_all
{
	t_vec		crd;
	t_scl		scale;
	t_window	win;
	t_line		line;
}				t_all;

void	feed_tab(char **file, int lines, t_all	*vars);

// line functions
int		ft_color(const char *s);
void	draw_p(t_all *var, int flag);
void	draw_shape(t_all *var, int flag);
void	draw_rot(t_all *var, int flag);
void	draw(t_all *var);
void	fill_scale(t_scl *scale, float x);
void	fill_scale2(t_scl *scale, float x, char c);
void	draw_line_segment(t_window *window, t_vec crd, t_all *var);
void	fr(int **tab, int **col, char ***split);
void	update_line_step(t_all *var, t_vec *crd);
void	ft_get_values(t_all *var);

// hook functions
void	keys(int k, t_all *var);
int		keyhook(int keycode, t_all *var);
int		ft_close(t_all *var);
void	initialisation(t_all *var, int flag);
void	hook_manipulation(t_all *var);
int		mouse_press(int button, int x, int y, t_all *var);
int		mouse_release(int button, int x, int y, t_all *var);
int		mouse_move(int x, int y, t_all *var);

#endif