/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:57:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/31 19:11:49 by lduboulo         ###   ########.fr       */
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
