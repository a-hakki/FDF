/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/21 21:47:47 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_all *var)
{
	mlx_destroy_image(var->win.mlx, var->win.img);
	mlx_destroy_window(var->win.mlx, var->win.win);
	mlx_destroy_display(var->win.mlx);
	if (var->win.mlx)
		free(var->win.mlx);
	return (fr(var->crd.tab, var->crd.color, NULL), exit(1), 0);
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
		var->scale.rot_direction = 0;
	}
	if (flag)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
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
	char	*s;

	mlx_clear_window(var->win.mlx, var->win.win);
	set_separite_line(var, 0xffffff);
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->win.img, \
		0, (M_H * 10 / 100));
	s = ft_strjoin(ft_strdup("X offset : "), ft_itoa(var->scale.x_offset));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 15 / 100, M_H * 6 / 100, \
		0xffffff, s);
	free(s);
	s = ft_strjoin(ft_strdup("Y offset : "), ft_itoa(var->scale.y_offset));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 45 / 100, M_H * 6 / 100, \
		0xffffff, s);
	free(s);
	s = ft_strjoin(ft_strdup("Z value  : "), ft_itoa(var->scale.z));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 75 / 100, M_H * 6 / 100, \
		0xffffff, s);
	free(s);
	mlx_hook(var->win.win, 4, 1L << 2, mouse_press, var);
	mlx_hook(var->win.win, 5, 1L << 3, mouse_release, var);
	mlx_hook(var->win.win, 6, 1L << 6, mouse_move, var);
	mlx_key_hook(var->win.win, keyhook, var);
	mlx_hook(var->win.win, 17, 1L << 0, ft_close, var);
	mlx_loop(var->win.mlx);
}
