/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrsx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:10:05 by ahakki            #+#    #+#             */
/*   Updated: 2024/11/20 11:54:00 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putadrsx(int fd, size_t a, char c)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	i = 0;
	s = "0123456789abcdef";
	if (a > 15)
		i = ft_putadrsx(fd, (a / 16), c);
	if (i == -1)
		return (-1);
	len += i;
	if (c == 'X')
		s = "0123456789ABCDEF";
	i = write(fd, &(s[a % 16]), 1);
	if (i == -1)
		return (-1);
	return (len + i);
}
