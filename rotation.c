/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:25 by kali              #+#    #+#             */
/*   Updated: 2025/02/06 09:15:12 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_point_z(float *x, float *y, float theta_z)
{
	float	rad_z;
	float	temp_x;

	rad_z = theta_z * (M_PI / 180.0);
	temp_x = *x * cos(rad_z) - *y * sin(rad_z);
	*y = *x * sin(rad_z) + *y * cos(rad_z);
	*x = temp_x;
}

void	get_crd_colomns_rot(t_all *strct, int i, int j, float theta_z)
{
	t_rot	rot;

	rot.x0 = i * strct->scale.x - j * strct->scale.y;
	rot.y0 = i * strct->scale.x + j * strct->scale.y;
	rot.z0 = strct->crd.tab[j][i] * strct->scale.z;
	rot.x1 = (i + 1) * strct->scale.x - j * strct->scale.y;
	rot.y1 = (i + 1) * strct->scale.x + j * strct->scale.y;
	rot.z1 = strct->crd.tab[j][i + 1] * strct->scale.z;
	rotate_point_z(&rot.x0, &rot.y0, theta_z);
	rotate_point_z(&rot.x1, &rot.y1, theta_z);
	strct->crd.x0 = strct->scale.x_offset + rot.x0 * cos(M_PI / 6);
	strct->crd.y0 = strct->scale.y_offset + rot.y0 * sin(M_PI / 6) - rot.z0;
	strct->crd.x1 = strct->scale.x_offset + rot.x1 * cos(M_PI / 6);
	strct->crd.y1 = strct->scale.y_offset + rot.y1 * sin(M_PI / 6) - rot.z1;
	strct->crd.c_end = strct->crd.color[j][i + 1];
	draw_line_segment(&strct->win, strct->crd, strct);
}

void	get_crd_lines_rot(t_all *strct, int i, int j, float theta_z)
{
	t_rot	rot;

	rot.x0 = i * strct->scale.x - j * strct->scale.y;
	rot.y0 = i * strct->scale.x + j * strct->scale.y;
	rot.z0 = strct->crd.tab[j][i] * strct->scale.z;
	rot.x1 = i * strct->scale.x - (j + 1) * strct->scale.y;
	rot.y1 = i * strct->scale.x + (j + 1) * strct->scale.y;
	rot.z1 = strct->crd.tab[j + 1][i] * strct->scale.z;
	rotate_point_z(&rot.x0, &rot.y0, theta_z);
	rotate_point_z(&rot.x1, &rot.y1, theta_z);
	strct->crd.x0 = strct->scale.x_offset + rot.x0 * cos(M_PI / 6);
	strct->crd.y0 = strct->scale.y_offset + rot.y0 * sin(M_PI / 6) - rot.z0;
	strct->crd.x1 = strct->scale.x_offset + rot.x1 * cos(M_PI / 6);
	strct->crd.y1 = strct->scale.y_offset + rot.y1 * sin(M_PI / 6) - rot.z1;
	strct->crd.c_end = strct->crd.color[j + 1][i];
	draw_line_segment(&strct->win, strct->crd, strct);
}

void	draw_rot(t_all *var, int flag)
{
	int	i;
	int	j;

	j = 0;
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
				get_crd_colomns_rot(var, i, j, 6 * var->scale.rot_direction);
			if (j + 1 < var->crd.lines)
				get_crd_lines_rot(var, i, j, 6 * var->scale.rot_direction);
			i++;
		}
		j++;
	}
	hook_manipulation(var);
}
