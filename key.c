/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:45:31 by kali              #+#    #+#             */
/*   Updated: 2025/02/08 22:06:28 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keys(int k, t_all *var)
{
	if (k == 't')
		fill_scale2(&var->scale, 0.5, '*');
	if (k == 'n')
		fill_scale2(&var->scale, 0.5, '/');
	if (k == 'b')
	{
		var->scale.rot_direction = 0;
		var->scale.flag = 0;
		fill_scale(var, 1.7);
	}
	if (k == 'z')
		var->scale.z += 0.5;
	if (k == 'x')
		var->scale.z -= 0.5;
	if (k == 'p')
		var->scale.projection = 'p';
	if (k == 'i')
		var->scale.projection = 'i';
	if (k == 65361)
		var->scale.rot_direction += 1;
	if (k == 65363)
		var->scale.rot_direction -= 1;
	draw(var);
}

int	keyhook(int k, t_all *var)
{
	if (k == 65307)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
		mlx_destroy_window(var->win.mlx, var->win.win);
		mlx_destroy_display(var->win.mlx);
		if (var->win.mlx)
			free(var->win.mlx);
		return (fr(var->crd.tab, var->crd.color, NULL), exit(1), 0);
	}
	if (ft_strrchr("tnbzxpi", k) || k == 65361 || k == 65363)
		keys(k, var);
	return (0);
}
