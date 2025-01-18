/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/01/18 13:41:20 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_transition(int key, t_all *var)
// {
// 	if (key == 65361)
// 		fill_scale2(&var->scale, 0.5, '3');
// 	if (key == 65363)
// 		fill_scale2(&var->scale, 0.5, '1');
// 	if (key == 65362)
// 		fill_scale2(&var->scale, 0.5, '4');
// 	if (key == 65364)
// 		fill_scale2(&var->scale, 0.5, '2');
// 	draw_shape(var, 1);
// }

int	keyhook(int k, t_all *var)
{
	if (k == 65307)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
		exit(0);
	}
	if ( k == 'o' || k == 'i' || k == 'b'|| k == 'z' || k == 'x')
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
	// if (k >= 65361 && k <= 65364)
	// 	ft_transition(k, var);
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
		var->win.addr = mlx_get_data_addr(var->win.img, &var->win.bits_per_pixel,
				&var->win.line_length, &var->win.endian);
		var->scale.mouse_pressed = 0;
		var->scale.x_ms = 0;
		var->scale.y_ms = 0;
	}
	if (flag)
	{
		var->win.img = mlx_new_image(var->win.mlx, M_W, M_H);
		var->win.addr = mlx_get_data_addr(var->win.img, &var->win.bits_per_pixel, \
			&var->win.line_length, &var->win.endian);
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
int mouse_press(int button, int x, int y, t_all *var)
{
    if (button == 1) // Left mouse button pressed
    {
        var->scale.x_ms = x;
        var->scale.y_ms = y;
        var->scale.mouse_pressed = 1; // Track that the button is held
    }
    return (0);
}
int mouse_release(int button, int x, int y, t_all *var)
{
    if (button == 1) // Left mouse button released
    {
        (void)x;
        (void)y;
        var->scale.mouse_pressed = 0; // Stop tracking
    }
    return (0);
}
int mouse_move(int x, int y, t_all *var)
{
    if (var->scale.mouse_pressed) // Only track if the button is held
    {
        int delta_x = x - var->scale.x_ms;
        int delta_y = y - var->scale.y_ms;

        var->scale.x_offset += delta_x;
        var->scale.y_offset += delta_y;

        var->scale.x_ms = x;
        var->scale.y_ms = y;

        draw_shape(var, 1); // Redraw with the updated offsets
    }
    return (0);
}

void	hook_manipulation(t_all *var)
{
	mlx_clear_window(var->win.mlx, var->win.win);
	set_background_color(var, 0xffffff);
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->win.img, M_W * 10 / 100, 0);
	mlx_string_put(var->win.mlx, var->win.win, M_W * 2 / 100, M_H * 10 / 100, 0xffffff, ft_strjoin("X offset : ", ft_itoa(var->scale.x_offset)));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 2 / 100, M_H * 15 / 100, 0xffffff, ft_strjoin("Y offset : ", ft_itoa(var->scale.y_offset)));
	mlx_string_put(var->win.mlx, var->win.win, M_W * 2 / 100, M_H * 20 / 100, 0xffffff, ft_strjoin("Z value  : ", ft_itoa(var->scale.z)));
	mlx_hook(var->win.win, 4, 1L << 2, mouse_press, var);  // Mouse press
    mlx_hook(var->win.win, 5, 1L << 3, mouse_release, var); // Mouse release
    mlx_hook(var->win.win, 6, 1L << 6, mouse_move, var);    // Mouse move
	mlx_key_hook(var->win.win, keyhook, var);
	mlx_hook(var->win.win, 17, 1L << 0, ft_close, &var->win);
	mlx_loop(var->win.mlx);
}
