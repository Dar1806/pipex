/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:16:10 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/16 10:59:13 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	write_read(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error : Can't open file\n", 1);
		exit(1);
	}
	return (fd);
}

void	child(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = write_read(av[1], 0);
	if (dup2(fd, 0) == -1)
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(fd);
	close(pipefd[0]);
	if (dup2(pipefd[1], 1) == -1)
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(pipefd[1]);
	exec_cmd(av[2], env);
}

void	parent(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = write_read(av[4], 1);
	if (dup2(fd, 1) == -1)
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(fd);
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1)
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(pipefd[0]);
	exec_cmd(av[3], env);
}
