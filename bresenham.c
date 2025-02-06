/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:32:38 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/06 10:21:44 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fraction(int step, int total_step)
{
	if (total_step == 0)
		return (0.0f);
	else
		return ((float)step / (float)total_step);
}

void	ft_get_values(t_all *var)
{
	var->line.dx = ft_abs(var->crd.x1 - var->crd.x0);
	var->line.dy = ft_abs(var->crd.y1 - var->crd.y0);
	if (var->crd.x0 < var->crd.x1)
		var->line.sx = 1;
	else
		var->line.sx = -1;
	if (var->crd.y0 < var->crd.y1)
		var->line.sy = 1;
	else
		var->line.sy = -1;
	var->line.err = var->line.dx - var->line.dy;
}

void	update_line_step(t_all *var, t_vec *crd)
{
	var->line.e2 = 2 * var->line.err;
	if (var->line.e2 > -var->line.dy)
	{
		var->line.err -= var->line.dy;
		crd->x0 += var->line.sx;
	}
	if (var->line.e2 < var->line.dx)
	{
		var->line.err += var->line.dx;
		crd->y0 += var->line.sy;
	}
}

unsigned int	interpolate_color(unsigned int start, unsigned int end, float t)
{
	t_color	color;

	color.r = (start >> 16) & 0xFF;
	color.g = (start >> 8) & 0xFF;
	color.b = start & 0xFF;
	color.r2 = (end >> 16) & 0xFF;
	color.g2 = (end >> 8) & 0xFF;
	color.b2 = end & 0xFF;
	color.r_interp = color.r + (int)((color.r2 - color.r) * t);
	color.g_interp = color.g + (int)((color.g2 - color.g) * t);
	color.b_interp = color.b + (int)((color.b2 - color.b) * t);
	return ((color.r_interp & 0xFF) << 16) | ((color.g_interp & 0xFF) << 8) | (color.b_interp & 0xFF);
}

void	draw_line_segment(t_window *window, t_vec crd, t_all *var)
{
	char	*dst;
	int		total_step;
	int		step;

	step = 0;
	while ((crd.x1 > M_W || crd.y1 > M_H) && var->scale.flag == 0)
			keys('n', var);
	ft_get_values(var);
	total_step = ft_abs(ft_max(var->line.dx, var->line.dy));
	while (1)
	{
		if (crd.x0 >= 0 && crd.x0 < window->line_length / 4 &&
			crd.y0 >= 0 && crd.y0 < M_H)
		{
			dst = window->addr + (crd.y0 * window->line_length + 
					crd.x0 * (window->bpp / 8));
			*(unsigned int *)dst = interpolate_color(crd.c, crd.c_end, fraction(step, total_step));
		}
		if (crd.x0 == crd.x1 && crd.y0 == crd.y1)
			break;
		update_line_step(var, &crd);
		step++;
	}
}
