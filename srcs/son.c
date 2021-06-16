/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   son.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:36:40 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/16 16:43:24 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_son(int *fd)
{
	close(fd[READ_END]); // impedimos que el padre escriba, solo queremos que lea
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execlp("/bin/ls", "ls", "-l", NULL);
}
