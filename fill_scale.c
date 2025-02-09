/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:29 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/09 16:18:27 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_scale(t_all *var, float x)
{
	float	iso_x;
	float	iso_y;

	var->scale.x = 10 * x;
	var->scale.y = 10 * x;
	var->scale.z = 10 * x;
	iso_x = ((var->crd.columns - 1) * var->scale.x - (var->crd.lines - 1) \
	* var->scale.y) * cos(M_PI / 6);
	iso_y = ((var->crd.columns - 1) * var->scale.x + (var->crd.lines - 1) \
	* var->scale.y) * sin(M_PI / 6);
	var->scale.x_offset = (M_W - iso_x) / 2;
	var->scale.y_offset = (M_H - iso_y) / 2;
}

void	fill_scale2(t_scl *scale, float x, char c)
{
	if (c == '*' && scale->x < 100 && scale->y < 100)
	{
		scale->x *= (1 + x);
		scale->y *= (1 + x);
		scale->z *= (1 + x);
	}
	else if (c == '/' && scale->x > 1 && scale->y > 1)
	{
		scale->x *= (1 - x);
		scale->y *= (1 - x);
		scale->z *= (1 - x);
	}
	else if (c == '1')
		scale->x_offset += 10;
	else if (c == '3')
		scale->x_offset -= 10;
	else if (c == '2')
		scale->y_offset += 10;
	else if (c == '4')
		scale->y_offset -= 10;
}
