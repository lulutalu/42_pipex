/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_functions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:21:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/06 14:34:28 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	end_fd_close(t_fd *fd)
{
	close(fd->input);
	close(fd->output);
	close(fd->outfile);
	close(fd->io[FD_IN]);
	close(fd->io[FD_OU]);
}
