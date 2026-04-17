/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:00:00 by nmeunier          #+#    #+#             */
/*   Updated: 2026/04/17 17:47:32 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd_not_found(char *name, char **tab_cmd)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	free_tab(tab_cmd);
	exit(127);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**tab_cmd;
	char	*path;

	if (!cmd || cmd[0] == '\0')
		cmd_not_found(NULL, NULL);
	tab_cmd = ft_split(cmd, ' ');
	if (!tab_cmd || !tab_cmd[0] || tab_cmd[0][0] == '\0')
		cmd_not_found(NULL, tab_cmd);
	path = get_path(tab_cmd[0], env);
	if (!path)
		cmd_not_found(tab_cmd[0], tab_cmd);
	execve(path, tab_cmd, env);
	ft_putstr_fd("pipex: execve failed\n", 2);
	free(path);
	free_tab(tab_cmd);
	exit(126);
}
