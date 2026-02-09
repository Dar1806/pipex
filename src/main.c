/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:20:28 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/09 12:58:45 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(void)
{
	int	id;

	id = fork();
	printf("id : %d\n", id);
	if (id == 0)
		printf("child\n");
	else
		printf("parent\n");
	return (0);
}
