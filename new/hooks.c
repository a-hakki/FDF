/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 21:50:01 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyhook(int key, t_all *var)
{
	if (key == 65307)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
		mlx_clear_window(var->win.mlx, var->win.win);
		exit(0);
	}
	else if (key == 'o')
	{
		fill_scale2(&var->scale, 0.5, '*');
		mlx_clear_window(var->win.mlx, var->win.win);
		draw_shape(var, 1);
	}
	else if (key == 'i')
	{
		fill_scale2(&var->scale, 0.5, '/');
		mlx_clear_window(var->win.mlx, var->win.win);
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

void	initialisation(t_window *window, int flag)
{
	if (!flag)
	{
		window->mlx = mlx_init();
		window->win = mlx_new_window(window->mlx, 1000, 1000, "Hello world!");
		window->img = mlx_new_image(window->mlx, 1000, 1000);
		window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
				&window->line_length, &window->endian);
	}
	if (flag)
	{
		window->img = mlx_new_image(window->mlx, 1000, 1000);
		window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, \
			&window->line_length, &window->endian);
	}
}

void	hook_manipulation(t_all *var)
{
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->win.img, 0, 0);
	mlx_key_hook(var->win.win, keyhook, var);
	mlx_hook(var->win.win, 17, 1L << 0, ft_close, &var->win);
	mlx_loop(var->win.mlx);
}
