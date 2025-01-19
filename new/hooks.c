/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/19 15:06:24 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyhook(int k, t_all *var)
{
	if (k == 65307)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
		exit(0);
	}
	if (k == 'o' || k == 'i' || k == 'b' || k == 'z' || k == 'x')
	{
		if (k == 'o')
			fill_scale2(&var->scale, 0.5, '*');
		if (k == 'i')
			fill_scale2(&var->scale, 0.5, '/');
		if (k == 'b')
			fill_scale(&var->scale, 1.7);
		if (k == 'z')
			var->scale.z += 0.5;
		if (k == 'x')
			var->scale.z -= 0.5;
		draw_shape(var, 1);
	}
	return (0);
}

int	ft_close(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}

void	initialisation(t_all *var, int flag)
{
	if (!flag)
	{
		var->win.mlx = mlx_init();
		var->win.win = mlx_new_window(var->win.mlx, M_W, M_H, "Hello world!");
		var->win.img = mlx_new_image(var->win.mlx, M_W, M_H);
		var->win.addr = mlx_get_data_addr(var->win.img, &var->win.bpp,
				&var->win.line_length, &var->win.endian);
		var->scale.mouse_pressed = 0;
		var->scale.x_ms = 0;
		var->scale.y_ms = 0;
	}
	if (flag)
	{
		var->win.img = mlx_new_image(var->win.mlx, M_W, M_H);
		var->win.addr = mlx_get_data_addr(var->win.img, &var->win.bpp, \
			&var->win.line_length, &var->win.endian);
	}
}

void	set_separite_line(t_all *var, int color)
{
	int	x;

	x = 0;
	while (x < M_W)
	{
		mlx_pixel_put(var->win.mlx, var->win.win, \
			x, (M_H * 10 / 100) - 1, color);
		x++;
	}
}

void	hook_manipulation(t_all *var)
{
	mlx_clear_window(var->win.mlx, var->win.win);
	set_separite_line(var, 0xffffff);
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->win.img, \
		0, (M_H * 10 / 100));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 15 / 100, M_H * 6 / 100, \
		0xffffff, ft_strjoin("X offset : ", ft_itoa(var->scale.x_offset)));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 45 / 100, M_H * 6 / 100, \
		0xffffff, ft_strjoin("Y offset : ", ft_itoa(var->scale.y_offset)));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 75 / 100, M_H * 6 / 100, \
		0xffffff, ft_strjoin("Z value  : ", ft_itoa(var->scale.z)));
	mlx_hook(var->win.win, 4, 1L << 2, mouse_press, var);
	mlx_hook(var->win.win, 5, 1L << 3, mouse_release, var);
	mlx_hook(var->win.win, 6, 1L << 6, mouse_move, var);
	mlx_key_hook(var->win.win, keyhook, var);
	mlx_hook(var->win.win, 17, 1L << 0, ft_close, &var->win);
	mlx_loop(var->win.mlx);
}
