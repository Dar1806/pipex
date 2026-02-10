/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:16:10 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/10 18:18:14 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	write_read(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_CREAT);
	if (fd == -1)
		exit(1);
	return (fd);
}

void	child_process(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = write_read(av[1], 0);
	dup2(fd, 0);
	//dup2(pipefd[1], 1);
	close(pipefd[0]);
	execve(av[1], av + 1, env);
	exit(1);
}

/* void	parent_process(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = write_read(av[4], 1);
} */
