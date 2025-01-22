/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:32:16 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/16 13:34:47 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_file_form(char *name, char *form)
{
	size_t	name_len;
	size_t	form_len;

	if (!name || !form)
		return (0);
	name_len = ft_strlen(name);
	form_len = ft_strlen(form);
	if (form_len > name_len)
		return (0);
	if (ft_strncmp(name + (name_len - form_len), form, form_len) == 0)
		return (1);
	return (0);
}
