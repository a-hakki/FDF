/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:25 by kali              #+#    #+#             */
/*   Updated: 2025/01/20 20:17:24 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_crd_colomns_p(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x);
	strct->crd.y0 = strct->scale.y_offset + (j * strct->scale.y);
	strct->crd.x1 = strct->scale.x_offset + ((i + 1) * strct->scale.x);
	strct->crd.y1 = strct->scale.y_offset + (j * strct->scale.y);
	draw_line_segment(&strct->win, strct->crd);
}

void	get_crd_lines_p(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x);
	strct->crd.y0 = strct->scale.y_offset + (j * strct->scale.y);
	strct->crd.x1 = strct->scale.x_offset + (i * strct->scale.x);
	strct->crd.y1 = strct->scale.y_offset + ((j + 1) * strct->scale.y);
	draw_line_segment(&strct->win, strct->crd);
}

void	draw_p(t_all *var, int flag)
{
	int	i;
	int	j;

	j = 0;
	var->scale.projection = 'p';
	initialisation(var, flag);
	if (!var->win.mlx || !var->win.win)
		return ;
	while (j < var->crd.lines)
	{
		i = 0;
		while (i < var->crd.columns)
		{
			var->crd.c = var->crd.color[j][i];
			if (i + 1 < var->crd.columns)
				get_crd_colomns_p(var, i, j);
			if (j + 1 < var->crd.lines)
				get_crd_lines_p(var, i, j);
			i++;
		}
		j++;
	}
	hook_manipulation(var);
}

void	draw(t_all *var)
{
	if (var->scale.projection == 'p')
		draw_p(var, 1);
	if (var->scale.projection == 'i')
		draw_shape(var, 1);
}
