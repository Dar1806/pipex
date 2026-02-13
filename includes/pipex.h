/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:54:24 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/13 23:44:10 by nmeunier         ###   ########.fr       */
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

void	parent(char **av, char **env, int *pipefd);
void	child(char **av, char **env, int *pipefd);
char	*ft_getenv(char **env);
int		write_read(char *file, int mode);
void	exec_cmd(char *cmd, char **env);
char	*get_path(char *cmd, char **env);
void	free_tab(char **tab);

#endif