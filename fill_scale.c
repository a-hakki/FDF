/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:58:29 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/05 20:24:51 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_scale(t_scl *scale, float x)
{
	scale->x = 10 * x;
	scale->y = 10 * x;
	scale->z = 10 * x;
	scale->x_offset = M_W * 450 / 1000;
	scale->y_offset = M_H * 250 / 1000;
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
