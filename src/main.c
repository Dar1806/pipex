/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:20:28 by nmeunier          #+#    #+#             */
/*   Updated: 2026/04/17 17:47:36 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_args(int ac, char **env)
{
	if (env == NULL || env[0] == NULL)
		return (ft_putstr_fd("Error : No environment variables\n", 2), 1);
	if (ac != 5)
		return (ft_putstr_fd("Error : Wrong number of arguments\n", 2), 1);
	return (0);
}

int	wait_children(int pid1, int pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int	pid1;
	int	pid2;
	int	pipefd[2];

	if (check_args(ac, env))
		return (1);
	if (pipe(pipefd) == -1)
		return (ft_putstr_fd("Error : pipe failed\n", 2), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (ft_putstr_fd("Error : fork failed\n", 2), 1);
	if (pid1 == 0)
		child(av, env, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		return (ft_putstr_fd("Error : fork failed\n", 2), 1);
	if (pid2 == 0)
		parent(av, env, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	return (wait_children(pid1, pid2));
}
