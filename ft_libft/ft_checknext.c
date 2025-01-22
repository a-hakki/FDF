/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:27:27 by ahakki            #+#    #+#             */
/*   Updated: 2024/11/22 15:48:48 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checknext(int fd, const char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(fd, va_arg(arg, int));
	if (c == 's')
		i = ft_putstr(fd, va_arg(arg, char *));
	if (c == 'p')
		i = ft_putadrs(fd, va_arg(arg, void *));
	if (c == 'i' || c == 'd')
		i = ft_putnum(fd, va_arg(arg, int));
	if (c == 'u')
		i = ft_putunum(fd, va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
		i = ft_puthex(fd, va_arg(arg, unsigned int), c);
	if (c == '%')
		i = write(fd, "%", 1);
	if (i == -1)
		return (-1);
	return (i);
}
