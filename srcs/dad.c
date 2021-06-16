/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:36:40 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/16 17:58:24 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_dad(int *fd, pid_t pid)
{
	close(fd[WRITE_END]);
	pid = fork();
	if (pid == 0)
		ft_daughter(fd);
	else if (pid == -1)
	{
		perror("Error");
		exit(-1);
	}
	else
		close(fd[READ_END]);
}
