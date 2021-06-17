/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:37 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/17 17:04:47 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char *pathing(char *command, char **envp)
{
	char *the_path;
	char **paths;
	int i;
	int fd;

	the_path = NULL;
	i = 0;
	paths = ft_split(envp[14], ':');
	paths[0] = ft_strchr(paths[0], '/');
	
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], command);
		fd = open(paths[i], O_RDONLY);
		if (fd >= 0)
		{
			the_path = paths[i];
			//ft_free_matrix(paths);
			close(fd);
			return (the_path);
		}
		i++;
	}
	//ft_free_matrix(paths);
	return (the_path);
}