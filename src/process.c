/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:16:10 by nmeunier          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/17 12:00:00 by nmeunier         ###   ########.fr       */
=======
/*   Updated: 2026/02/24 13:30:10 by nmeunier         ###   ########.fr       */
>>>>>>> 363c4289cbc34f965fdfc4e5e213a1ed6958f53e
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	write_read(char *file, int mode, int *pipefd)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
<<<<<<< HEAD
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": cannot open file\n", 2);
=======
		ft_putstr_fd("Error : Can't open file\n", 1);
		close(pipefd[0]);
		close(pipefd[1]);
>>>>>>> 363c4289cbc34f965fdfc4e5e213a1ed6958f53e
		exit(1);
	}
	return (fd);
}

void	child(char **av, char **env, int *pipefd)
{
	int	fd;

<<<<<<< HEAD
	fd = write_read(av[1], 0);
	if (dup2(fd, STDIN_FILENO) == -1)
=======
	fd = write_read(av[1], 0, pipefd);
	if (dup2(fd, 0) == -1)
>>>>>>> 363c4289cbc34f965fdfc4e5e213a1ed6958f53e
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(av[2], env);
}

void	parent(char **av, char **env, int *pipefd)
{
	int	fd;

<<<<<<< HEAD
	fd = write_read(av[4], 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
=======
	fd = write_read(av[4], 1, pipefd);
	if (dup2(fd, 1) == -1)
>>>>>>> 363c4289cbc34f965fdfc4e5e213a1ed6958f53e
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		ft_putstr_fd("Error : Can't dup2\n", 2);
		exit(1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(av[3], env);
}
