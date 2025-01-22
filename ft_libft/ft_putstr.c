/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:06:12 by ahakki            #+#    #+#             */
/*   Updated: 2024/11/20 14:02:29 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(int fd, const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (ft_putstr(fd, "(null)"));
	while (s[len])
	{
		i = write(fd, &s[len], 1);
		if (i == -1)
			return (-1);
		len++;
	}
	return (len);
}
