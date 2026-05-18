/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:20:28 by nmeunier          #+#    #+#             */
/*   Updated: 2026/05/18 15:42:54 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_args(int ac, char **env)
{
	if (env == NULL || env[0] == NULL)
		return (ft_putstr_fd("Error : No environment variables\n", 2), 1);
	if (ac < 5)
		return (ft_putstr_fd("Error : Wrong number of arguments\n", 2), 1);
	return (0);
}

int	open_pipes(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds - 1)
	{
		if (pipe(data->pipes + i * 2) == -1)
			return (ft_putstr_fd("Error : pipe failed\n", 2), 1);
		i++;
	}
	return (0);
}

int	fork_children(char **av, char **env, t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds)
	{
		data->pids[i] = fork();
		if (data->pids[i] == -1)
			return (ft_putstr_fd("Error : fork failed\n", 2), 1);
		if (data->pids[i] == 0)
			run_child(i, av, env, data);
		i++;
	}
	return (0);
}

int	init_data(int ac, char **av, t_pipex *data)
{
	data->here_doc = (ft_strncmp(av[1], "here_doc", 8) == 0);
	if (data->here_doc)
		data->nb_cmds = ac - 4;
	else
		data->nb_cmds = ac - 3;
	data->pipes = malloc(sizeof(int) * (data->nb_cmds - 1) * 2);
	data->pids = malloc(sizeof(pid_t) * data->nb_cmds);
	if (!data->pipes || !data->pids)
		return (ft_putstr_fd("Error : malloc failed\n", 2), 1);
	if (data->here_doc)
		data->here_fd = exec_here_doc(av[2]);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;
	int		ret;

	if (check_args(ac, env))
		return (1);
	if (init_data(ac, av, &data))
		return (1);
	if (open_pipes(&data) || fork_children(av, env, &data))
		return (1);
	ret = 0;
	while (ret < data.nb_cmds - 1)
	{
		close(data.pipes[ret * 2]);
		close(data.pipes[ret * 2 + 1]);
		ret++;
	}
	ret = wait_children(&data);
	free(data.pipes);
	free(data.pids);
	return (ret);
}
