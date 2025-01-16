/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/16 21:44:06 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transition(int key, t_all *var)
{
	if (key == 65361)
	{
		fill_scale2(&var->scale, 0.5, '3');
		draw_shape(var, 1);
	}
	if (key == 65363)
	{
		fill_scale2(&var->scale, 0.5, '1');
		draw_shape(var, 1);
	}
	if (key == 65362)
	{
		fill_scale2(&var->scale, 0.5, '4');
		draw_shape(var, 1);
	}
	if (key == 65364)
	{
		fill_scale2(&var->scale, 0.5, '2');
		draw_shape(var, 1);
	}
}

int	keyhook(int key, t_all *var)
{
	if (key == 65307)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
		exit(0);
	}
	if (key >= 'a' && key <= 'z')
	{
		if (key == 'o')
			fill_scale2(&var->scale, 0.5, '*');
		if (key == 'i')
			fill_scale2(&var->scale, 0.5, '/');
		if (key == 'b')
			fill_scale(&var->scale, 1.7);
		if (key == 'z')
			var->scale.z += 0.5;
		if (key == 'x')
			var->scale.z -= 0.5;
		draw_shape(var, 1);
	}
	if (key >= 65361 && key <= 65364)
		ft_transition(key, var);
	return (0);
}

int	ft_close(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}

void	initialisation(t_window *window, int flag)
{
	if (!flag)
	{
		window->mlx = mlx_init();
		window->win = mlx_new_window(window->mlx, M_W, M_H, "Hello world!");
		window->img = mlx_new_image(window->mlx, M_W, M_H);
		window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
				&window->line_length, &window->endian);
	}
	if (flag)
	{
		window->img = mlx_new_image(window->mlx, M_W, M_H);
		window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, \
			&window->line_length, &window->endian);
	}
}
void set_background_color(t_all *var, int color)
{
    int y;

    y = 0;
    while (y < M_H)
	{
		mlx_pixel_put(var->win.mlx, var->win.win, (M_W * 10 / 100) -1 , y, color);
		y++;
	}
}

void	hook_manipulation(t_all *var)
{
	mlx_clear_window(var->win.mlx, var->win.win);
	set_background_color(var, 0xffffff);
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->win.img, M_W * 10 / 100, 0);
	mlx_string_put(var->win.mlx, var->win.win, M_W * 2 / 100, M_H * 10 / 100, 0xffffff, ft_strjoin("X offset : ", ft_itoa(var->scale.x_offset)));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 2 / 100, M_H * 15 / 100, 0xffffff, ft_strjoin("Y offset : ", ft_itoa(var->scale.y_offset)));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 2 / 100, M_H * 20 / 100, 0xffffff, ft_strjoin("Z value  : ", ft_itoa(var->scale.z)));
	mlx_key_hook(var->win.win, keyhook, var);
	mlx_hook(var->win.win, 17, 1L << 0, ft_close, &var->win);
	mlx_loop(var->win.mlx);
}
