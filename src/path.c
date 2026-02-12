/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:49 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/12 19:42:40 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_getenv(char *name, char **env)
{
}

char	*get_path(char *cmd, char **env)
{
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
