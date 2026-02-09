/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:20:28 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/09 16:31:05 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pipe_id;
	int	pipefd[2];

	av = NULL;
	if (ac != 5)
	{
		ft_putstr_fd("Error : Wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (0);
	pipe_id = fork();
	if (pipe_id == -1)
		return (0);
	printf("id : %d\n", pipe_id);
	if (pipe_id == 0)
		printf("child\n");
	else
		printf("parent\n");
	execve(av[1], av + 1, env);
	return (0);
}
