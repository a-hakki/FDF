/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:28 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/14 20:49:55 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin2(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*returned;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	returned = malloc(sizeof(char) * len1 + len2 + 1);
	if (!returned)
		return (free(s1), s1 = NULL, NULL);
	while (s1[++i])
		returned[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		returned[len1 + i] = s2[i];
		i++;
	}
	returned[len1 + i] = '\0';
	free(s1);
	return (returned);
}

static void	protected_alloc(char **saved, char **allocated)
{
	if (!*saved)
	{
		*saved = ft_strdup("");
		if (!*saved)
			*saved = NULL;
	}
	*allocated = malloc((size_t)BUFFER_SIZE + 1);
	if (!*allocated)
	{
		if (*saved)
			free(*saved);
		*saved = NULL;
	}
}

static void	ft_fre(char **saved, char **allocated)
{
	free(*saved);
	*saved = NULL;
	free(*allocated);
	allocated = NULL;
}

static char	*ft_get_line(char **saved, int readen)
{
	char	*temp_saved;
	char	*pos;

	if (readen > 0)
	{
		temp_saved = *saved;
		pos = ft_strchr(temp_saved, '\n');
		*saved = ft_strdup(pos + 1);
		*(pos + 1) = '\0';
		return (temp_saved);
	}
	temp_saved = ft_strdup(*saved);
	free(*saved);
	*saved = NULL;
	return (temp_saved);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*allocated;
	int				readen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	protected_alloc(&saved, &allocated);
	if (!saved || !allocated)
		return (ft_fre(&saved, &allocated), NULL);
	readen = 1;
	while (!(ft_strchr(saved, '\n')) && readen > 0)
	{
		readen = read(fd, allocated, BUFFER_SIZE);
		if (readen == 0)
			break ;
		if (readen == -1)
			return (ft_fre(&saved, &allocated), NULL);
		allocated[readen] = '\0';
		saved = ft_strjoin2(saved, allocated);
		if (!saved)
			return (ft_fre(&saved, &allocated), NULL);
	}
	if (ft_strcmp(saved, "") == 0)
		return (ft_fre(&saved, &allocated), NULL);
	return (free(allocated), ft_get_line(&saved, readen));
}
