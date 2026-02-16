/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:20:28 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/16 21:42:09 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pipe_id;
	int	pipefd[2];

	if (env == NULL || env[0] == NULL)
	{
		ft_putstr_fd("Error : No environment variables\n", 1);
		return (1);
	}
	if (ac != 5)
	{
		ft_putstr_fd("Error : Wrong number of arguments\n", 1);
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (1);
	pipe_id = fork();
	if (pipe_id == -1)
		return (1);
	if (pipe_id == 0)
		child(av, env, pipefd);
	else
		parent(av, env, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
