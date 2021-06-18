/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:37 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/18 18:43:56 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	search_for_line(char **envp)
{
	int		i;
	char	*cosa;

	i = 0;
	while (envp[i])
	{
		cosa = ft_strnstr(envp[i], "PATH=", 5);
		if (cosa != NULL)
			return (i);
		i++;
	}
	return (-1);
}

char	*pathing(char *command, char **envp)
{
	char	*the_path;
	char	**paths;
	int		i;
	int		fd;

	the_path = NULL;
	paths = ft_split(envp[search_for_line(envp)], ':');
	paths[0] = ft_strchr(paths[0], '/');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], command);
		fd = open(paths[i], O_RDONLY);
		if (fd >= 0)
		{
			the_path = ft_strdup(paths[i]);
			ft_free_matrix(paths);
			close(fd);
			return (the_path);
		}
		i++;
	}
	ft_free_matrix(paths);
	return (NULL);
}
