/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:14:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/30 18:40:12 by lduboulo         ###   ########.fr       */
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
			perror("Main open fd :");
		if (pipe(fd.io) < 0)
			perror("Main oepn pipe :");
		pars.cmd = argv[2];
		first.pid = fork();
		if (first.pid < 0)
			perror("Fork ");
		if (first.pid == 0)
    		first_child(&fd, &pars, envp);
		pars.cmd = argv[3];
		scnd.pid = fork();
		if (scnd.pid < 0)
			perror("Fork ");
		if (scnd.pid == 0)
			scnd_child(&fd, &pars, envp);
		close(fd.io[FD_IN]);
		close(fd.io[FD_OU]);
		waitpid(first.pid, NULL, 0);
		waitpid(scnd.pid, NULL, 0);
		exit(EXIT_SUCCESS);
	}
	else
		exit_error(N_ARGS);
	return (0);
}
