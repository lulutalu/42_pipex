/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:14:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/04 11:27:53 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	t_pid	first;
	t_pid	scnd;
	t_pars	pars;

	if (argc == 5)
	{
		fd.input = open(argv[1], O_RDONLY);
		fd.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd.outfile < 0 || fd.input < 0)
			ft_putstr_fd_count("No such file or directory\n", 2);
		if (pipe(fd.io) < 0)
			exit_error(0);
		pars.cmd = argv[2];
		first.pid = fork();
		if (first.pid < 0)
			exit_error(0);
		if (first.pid == 0)
    		first_child(&fd, &pars, envp);
		pars.cmd = argv[3];
		scnd.pid = fork();
		if (scnd.pid < 0)
			exit_error(0);
		if (scnd.pid == 0)
			scnd_child(&fd, &pars, envp);
		close(fd.io[FD_IN]);
		close(fd.io[FD_OU]);
		waitpid(first.pid, &first.status, 0);
		waitpid(scnd.pid, &scnd.status, 0);
		if (WIFEXITED(scnd.status) != 0)
			exit(WEXITSTATUS(scnd.status));
		exit(0);
	}
	else
	{
		ft_putstr_fd_count(N_ARGS, 2);
		exit_error(1);
	}
}
