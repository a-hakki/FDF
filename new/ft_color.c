/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:43:44 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 21:38:42 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid(const char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_color(const char *s)
{
	int	i;
	int	color;

	color = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != ',' && s[i])
		i++;
	if (!s[i])
		return (0xffffff);
	i++;
	if (s[i] == '0' && s[i + 1] == 'x')
	{
		i += 2;
		while (s[i] && is_valid(s[i]) != -1)
			color = (color * 16) + is_valid(s[i++]);
		return (color);
	}
	else
		return (0xffffff);
}

void	fill_scale2(t_scl *scale, float x, char c)
{
	if (c == '*')
	{
		scale->x += x;
		scale->y += x;
		scale->z += x / (scale->x + scale->y);
	}
	else if (c == '/' && scale->x > 0 && scale->y > 0)
	{
		scale->x -= x;
		scale->y -= x;
		scale->z -= x / (scale->x + scale->y);
	}
	scale->x_offset = 350;
	scale->y_offset = 250;
}
