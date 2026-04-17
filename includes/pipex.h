/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:54:24 by nmeunier          #+#    #+#             */
/*   Updated: 2026/04/17 17:47:22 by nmeunier         ###   ########.fr       */
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

char	*find_cmd_in_paths(char **path, char *cmd_name);
void	parent(char **av, char **env, int *pipefd);
void	cmd_not_found(char *name, char **tab_cmd);
void	child(char **av, char **env, int *pipefd);
int		wait_children(int pid1, int pid2);
int		write_read(char *file, int mode);
char	*get_path(char *cmd, char **env);
void	exec_cmd(char *cmd, char **env);
void	exec_cmd(char *cmd, char **env);
int		check_args(int ac, char **env);
char	*ft_getenv(char **env);
void	free_tab(char **tab);

#endif