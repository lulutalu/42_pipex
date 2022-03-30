/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:57:49 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/30 18:11:52 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	first_child(t_fd *fd, t_pars *pars, char **envp)
{
	fd->input = dup2(fd->input, STDIN_FILENO);
	if (fd->input < 0)
		perror("Child 1 fd input :");
	fd->output = dup2(fd->io[FD_IN], STDOUT_FILENO);
	if (fd->output < 0)
		perror("Child 1 fd output :");
	close(fd->io[FD_OU]);
	parsing_env(pars, envp);
}

void	scnd_child(t_fd *fd, t_pars *pars, char **envp)
{
	fd->input = dup2(fd->io[FD_OU], STDIN_FILENO);
	if (fd->input < 0)
		perror("Child 2 fd input :");
	close(fd->io[FD_IN]);
	fd->output = dup2(fd->outfile, STDOUT_FILENO);
	if (fd->output < 0)
		perror("Child 2 fd output :");
	parsing_env(pars, envp);
}
