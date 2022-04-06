/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:19:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/06 15:56:30 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

void	child_process(t_fd *fd, char **envp, char *cmd)
{
	t_pars	pars;

	pars.cmd = ft_strdup(cmd);
	if (fd->n == 2)
	{
		fd->input = dup2(fd->input, STDIN_FILENO);
		fd->output = dup2(fd->io[FD_IN], STDOUT_FILENO);
		close(fd->io[FD_OU]);
		exec_child(fd, &pars, envp);
	}
	if (fd->n == fd->argc - 2)
	{
		fd->input = dup2(fd->io[FD_OU], STDIN_FILENO);
		close(fd->io[FD_IN]);
		fd->output = dup2(fd->outfile, STDOUT_FILENO);
		exec_child(fd, &pars, envp);
	}
}

void	exec_child(t_fd *fd, t_pars *pars, char **envp)
{
	check_for_error(fd->input);
	check_for_error(fd->output);
	exit_error(parsing_env(pars, envp));
}
