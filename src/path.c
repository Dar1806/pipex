/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:49 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/13 20:36:54 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_getenv(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**path;
	char	**tab_cmd;
	char	*full_path;
	char	*is_ok;
	int		i;

	path = ft_split(ft_getenv(env), ':');
	tab_cmd = ft_split(cmd, ' ');
	i = -1;
	while (path[++i])
	{
		full_path = ft_strjoin(path[i], "/");
		is_ok = ft_strjoin(full_path, tab_cmd[0]);
		free(full_path);
		if (access(is_ok, F_OK | X_OK) == 0)
		{
			free_tab(path);
			free_tab(tab_cmd);
			return (is_ok);
		}
		free(is_ok);
	}
	free_tab(path);
	free_tab(tab_cmd);
	return (cmd);
}

void	free_tab(char **tab_cmd)
{
	int	i;

	if (!tab_cmd)
		return ;
	i = 0;
	while (tab_cmd[i])
	{
		free(tab_cmd[i]);
		i++;
	}
	free(tab_cmd);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**tab_cmd;
	char	*path;

	if (!cmd || cmd[0] == '\0')
		exit(127);
	tab_cmd = ft_split(cmd, ' ');
	if (!tab_cmd || !tab_cmd[0] || tab_cmd[0][0] == '\0')
	{
		free_tab(tab_cmd);
		exit(127);
	}
	path = get_path(tab_cmd[0], env);
	if (execve(path, tab_cmd, env) == -1)
	{
		free_tab(tab_cmd);
		exit(127);
	}
}
