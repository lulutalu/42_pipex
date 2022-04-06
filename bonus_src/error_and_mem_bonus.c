/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_mem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:20:23 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/05 15:19:41 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

void	exit_error(int status)
{
	if (status == 127)
		ft_putstr_fd_count("command not found\n", 2);
	exit(status);
}

void	free_tab(void **mem)
{
	int	i;

	i = 0;
	while (mem[i] != NULL)
		i++;
	while (i > 0)
		free(mem[i--]);
	free(mem);
}

void	check_for_error(int value)
{
	if (value < 0)
		exit_error(0);
}
