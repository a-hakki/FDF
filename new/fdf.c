/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:45:31 by kali              #+#    #+#             */
/*   Updated: 2025/01/16 20:18:06 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// --------execute command----------
// gcc fdf.c libmlx.a libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux
// -lXext -lX11 -lm -lz libftprintf.a libgetnextline.a -g

int	mycmp(char *s)
{
	int	l;

	l = ft_strlen(s) - 1;
	if (l + 1 >= 5)
	{
		if (!ft_strncmp(&s[l - 3], ".fdf", 4))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**file;
	int		fd;
	int		i;
	t_all	vars;
	t_all	*a;

	i = 0;
	if (ac == 2 && mycmp(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (perror("Failed to open file"), 1);
		file = ft_read(fd, av[1]);
		if (!file)
			return (close(fd), perror("Failed to read file"), 1);
		while (file[i])
			i++;
		a = feed_tab(file, i, &vars);
		fill_scale(&vars.scale, 1.7);
		draw_shape(a, 0);
		return (ft_free("2", file), close(fd), 0);
	}
	printfd(2, "Invalid Argument\n");
	printfd(2, "\tExpected Format: ./fdf <filename.fdf>\n");
}
