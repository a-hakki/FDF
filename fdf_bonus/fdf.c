/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:45:31 by kali              #+#    #+#             */
/*   Updated: 2025/01/14 11:03:08 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// --------execute command----------
// gcc x.c libmlx.a libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux 
// -lXext -lX11 -lm -lz libftprintf.a libgetnextline.a -g

void	free_alloc(int **tab, int **col, char ***split)
{
	if (tab)
		free(tab);
	if (col)
		free(col);
	if (split)
		free(split);
}

char	***ft_alloc_all(t_all *vars, int lines, char **file)
{
	int		i;
	char	***sp_fl;

	i = 0;
	vars->crd.tab = (int **)malloc(lines * sizeof(int *));
	vars->crd.color = (int **)malloc(lines * sizeof(int *));
	sp_fl = (char ***)malloc((lines + 1) * sizeof(char **));
	if (!vars->crd.tab || !vars->crd.color || !sp_fl)
	{
		free_alloc(vars->crd.tab, vars->crd.color, sp_fl);
		exit(1);
	}
	while (file[i])
	{
		sp_fl[i] = ft_split(ft_strtrim(file[i], "\n "), ' ');
		i++;
	}
	sp_fl[lines] = NULL;
	return (sp_fl);
}

t_all	*feed_tab(char **file, int lines, t_all	*vars)
{
	char	***sp_fl;
	int		i;
	int		j;

	i = 0;
	sp_fl = ft_alloc_all(vars, lines, file);
	while (sp_fl[i] != NULL)
	{
		vars->crd.tab[i] = (int *)malloc(ft_arrlen(sp_fl[i]) * sizeof(int *));
		vars->crd.color[i] = (int *)malloc(ft_arrlen(sp_fl[i]) * sizeof(int *));
		if (!vars->crd.tab[i] || !vars->crd.color)
			exit(1);
		j = 0;
		while (sp_fl[i][j])
		{
			vars->crd.tab[i][j] = ft_atoi(sp_fl[i][j]);
			vars->crd.color[i][j] = ft_color(sp_fl[i][j]);
			j++;
		}
		i++;
	}
	vars->crd.lines = i;
	vars->crd.columns = j;
	return (vars);
}

void	free_file(char **file, int line_counter)
{
	int	i;

	i = 0;
	while (i < line_counter)
	{
		if (file[i])
			free(file[i++]);
	}
	free(file);
}

int	main(int ac, char **av)
{
	char	**file;
	int		fd;
	int		i;
	t_all	vars;

	if (ac > 1 && ac <= 2)
	{
		i = 0;
		if (ft_file_form(av[1], ".fdf") == 0)
			return (perror("Bad form, expected form : <filename>.fdf"), 1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (perror("Failed to open file"), 1);
		file = ft_read(fd, av[1]);
		if (!file)
			return (close(fd), perror("Failed to read file"), 1);
		while (file[i])
			i++;
		draw_line(feed_tab(file, i, &vars));
		return (free_file(file, i), close(fd), 0);
	}
}
