/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:16:10 by nmeunier          #+#    #+#             */
/*   Updated: 2026/05/18 15:36:29 by nmeunier         ###   ########.fr       */
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
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": cannot open file\n", 2);
	}
	return (fd);
}

int	set_stdin(int i, char **av, t_pipex *data)
{
	int	fd;

	if (i == 0)
	{
		if (data->here_doc)
		{
			dup2(data->here_fd, STDIN_FILENO);
			close(data->here_fd);
			return (0);
		}
		fd = write_read(av[1], 0);
		if (fd == -1)
			return (1);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
		dup2(data->pipes[(i - 1) * 2], STDIN_FILENO);
	return (0);
}

int	set_stdout(int i, char **av, t_pipex *data)
{
	int		fd;
	int		outfile_idx;

	if (i == data->nb_cmds - 1)
	{
		outfile_idx = data->nb_cmds + 2 + data->here_doc;
		if (data->here_doc)
			fd = open(av[outfile_idx], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = write_read(av[outfile_idx], 1);
		if (fd == -1)
			return (1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		dup2(data->pipes[i * 2 + 1], STDOUT_FILENO);
	return (0);
}

void	close_all_pipes(t_pipex *data)
{
	int	j;

	j = 0;
	while (j < data->nb_cmds - 1)
	{
		close(data->pipes[j * 2]);
		close(data->pipes[j * 2 + 1]);
		j++;
	}
}

void	run_child(int i, char **av, char **env, t_pipex *data)
{
	if (set_stdin(i, av, data) || set_stdout(i, av, data))
	{
		close_all_pipes(data);
		free(data->pipes);
		free(data->pids);
		exit(1);
	}
	close_all_pipes(data);
	free(data->pipes);
	free(data->pids);
	exec_cmd(av[i + 2 + data->here_doc], env);
}
