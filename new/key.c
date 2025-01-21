/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:45:31 by kali              #+#    #+#             */
/*   Updated: 2025/01/21 14:48:39 by ahakki           ###   ########.fr       */
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
		fill_scale(&var->scale, 1.7);
	if (k == 'z')
		var->scale.z += 0.5;
	if (k == 'x')
		var->scale.z -= 0.5;
	if (k == 'p')
		var->scale.projection = 'p';
	if (k == 'i')
		var->scale.projection = 'i';
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
	if (ft_strrchr("tnbzxpi", k))
		keys(k, var);
	return (0);
}
