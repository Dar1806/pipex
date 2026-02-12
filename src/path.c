/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:49 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/12 21:01:53 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_getenv(char *name, char **env)
{
	int	i;
	int	j;
	char	*path;

	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		path = ft_substr(env[i], 0, j);
		if (ft_strcmp(name, env[i]) == 0)
		{
			free(path);
			fprintf(stderr, "PATH found : %s\n", env[i]);
			return (env[i] + j + 1);
		}
		free(path);
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*path;

	path = ft_getenv("PATH", env);
	cmd = ft_strjoin("/", path); 
	return (cmd);
}

void	free_tab(char **tab_cmd)
{
	int	i;

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

	tab_cmd = ft_split(cmd, ' ');
	path = get_path(tab_cmd[0], env);
	if (execve(path, tab_cmd, env) == -1)
	{
		ft_putstr_fd("Error : Command not found\n", 2);
		free_tab(tab_cmd);
		exit(0);
	}
}
