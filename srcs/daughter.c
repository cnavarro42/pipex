/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daughter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:55:57 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/16 17:45:48 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_daughter(int *fd)
{
	int	fd2;

	fd2 = open(FILE_NAME, O_WRONLY);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd2, STDOUT_FILENO);
	execlp("/usr/bin/wc", "wc", NULL);
}
