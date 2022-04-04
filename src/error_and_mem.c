/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:57:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/04 12:54:50 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

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

void	number_arg_check(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd_count(N_ARGS, 2);
		exit_error(1);
	}
}
