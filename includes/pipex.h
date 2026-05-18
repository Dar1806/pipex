/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:54:24 by nmeunier          #+#    #+#             */
/*   Updated: 2026/05/18 15:42:18 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_pipex
{
	int		*pipes;
	pid_t	*pids;
	int		nb_cmds;
	int		here_doc;
	int		here_fd;
}	t_pipex;

void	run_child(int i, char **av, char **env, t_pipex *data);
int		fork_children(char **av, char **env, t_pipex *data);
char	*find_cmd_in_paths(char **path, char *cmd_name);
int		set_stdout(int i, char **av, t_pipex *data);
int		init_data(int ac, char **av, t_pipex *data);
int		set_stdin(int i, char **av, t_pipex *data);
void	cmd_not_found(char *name, char **tab_cmd);
int		write_read(char *file, int mode);
char	*get_path(char *cmd, char **env);
void	exec_cmd(char *cmd, char **env);
int		check_args(int ac, char **env);
void	close_all_pipes(t_pipex *data);
int		wait_children(t_pipex *data);
int		exec_here_doc(char *limiter);
int		open_pipes(t_pipex *data);
char	*ft_getenv(char **env);
void	free_tab(char **tab);

#endif