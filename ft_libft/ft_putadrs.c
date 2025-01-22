/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:19 by ahakki            #+#    #+#             */
/*   Updated: 2024/11/20 12:02:26 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putadrs(int fd, void *p)
{
	int		i;
	int		len;
	size_t	a;

	a = (size_t)p;
	i = ft_putstr(fd, "0x");
	if (i == -1)
		return (-1);
	len = i;
	if (a == 0)
		return (write(fd, "0", 1) + len);
	i = ft_putadrsx(fd, a, 'x');
	if (i == -1)
		return (-1);
	len += i;
	return (len);
}
