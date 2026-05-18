/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:00:00 by nmeunier          #+#    #+#             */
/*   Updated: 2026/05/18 18:22:42 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*read_line(void)
{
	char	*line;
	char	buf;
	int		i;
	int		ret;

	line = malloc(4096);
	if (!line)
		return (NULL);
	i = 0;
	ret = read(0, &buf, 1);
	while (ret > 0 && buf != '\n')
	{
		line[i++] = buf;
		ret = read(0, &buf, 1);
	}
	line[i] = '\0';
	return (line);
}

int	exec_here_doc(char *limiter)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
	{
		ft_putstr_fd("Error : pipe failed\n", 2);
		exit(1);
	}
	ft_putstr_fd("> ", 1);
	line = read_line();
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter) + 1) != 0)
	{
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
		ft_putstr_fd("> ", 1);
		line = read_line();
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}
