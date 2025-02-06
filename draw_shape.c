/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:25 by kali              #+#    #+#             */
/*   Updated: 2025/02/06 09:33:25 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_crd_colomns(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + \
		(i * strct->scale.x - j * strct->scale.y) * cos(M_PI / 6);
	strct->crd.y0 = strct->scale.y_offset + \
		(i * strct->scale.x + j * strct->scale.y) * \
			sin(M_PI / 6) - (strct->crd.tab[j][i] * strct->scale.z);
	strct->crd.x1 = strct->scale.x_offset + \
		((i + 1) * strct->scale.x - j * strct->scale.y) * cos(M_PI / 6);
	strct->crd.y1 = strct->scale.y_offset + \
		((i + 1) * strct->scale.x + j * strct->scale.y) * \
			sin(M_PI / 6) - (strct->crd.tab[j][i + 1] * strct->scale.z);
	strct->crd.c_end = strct->crd.color[j][i + 1];
	draw_line_segment(&strct->win, strct->crd, strct);
}

void	get_crd_lines(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + \
		(i * strct->scale.x - j * strct->scale.y) * cos(M_PI / 6);
	strct->crd.y0 = strct->scale.y_offset + \
		(i * strct->scale.x + j * strct->scale.y) * \
			sin(M_PI / 6) - (strct->crd.tab[j][i] * strct->scale.z);
	strct->crd.x1 = strct->scale.x_offset + \
		(i * strct->scale.x - (j + 1) * strct->scale.y) * cos(M_PI / 6);
	strct->crd.y1 = strct->scale.y_offset + \
		(i * strct->scale.x + (j + 1) * strct->scale.y) * \
			sin(M_PI / 6) - (strct->crd.tab[j + 1][i] * strct->scale.z);
	strct->crd.c_end = strct->crd.color[j + 1][i];
	draw_line_segment(&strct->win, strct->crd, strct);
}

void	draw_shape(t_all *var, int flag)
{
	int	i;
	int	j;

	j = 0;
	var->scale.projection = 'i';
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
				get_crd_colomns(var, i, j);
			if (j + 1 < var->crd.lines)
				get_crd_lines(var, i, j);
			i++;
		}
		j++;
	}
	var->scale.flag = 1;
	hook_manipulation(var);
}
