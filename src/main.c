/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:20:28 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/10 18:19:03 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pipe_id;
	int	pipefd[2];

	if (ac != 4)
	{
		ft_putstr_fd("Error : Wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (0);
	pipe_id = fork();
	if (pipe_id == -1)
		return (0);
	if (pipe_id == 0)
		child_process(av, env, pipefd);
	else
		wait(NULL);
	return (0);
}
