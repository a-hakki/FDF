/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/08 18:25:38 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_window *window)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(window->mlx, window->img);
		mlx_destroy_window(window->mlx, window->win);
		exit(0);
	}
	return (0);
}

int	ft_close(int keycode, t_window *window)
{
	(void)keycode;
	printfd(2, "sffffffffg\n");
	mlx_destroy_image(window->mlx, window->img);
	return (0);
}

void	initialisation(t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 1000, 1000, "Hello world!");
	window->img = mlx_new_image(window->mlx, 1000, 1000);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel, \
		&window->line_length, &window->endian);
}

void	hook_manipulation(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	mlx_key_hook(window->win, key_hook, window);
	mlx_hook(window->win, 17, 1L << 0, ft_close, window);
	mlx_loop(window->mlx);
}
