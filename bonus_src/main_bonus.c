/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/06 15:57:47 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	t_pid	child;

	if (argc < 5)
	{
		ft_putstr_fd_count(N_ARGS, 2);
		exit_error(0);
	}
	fd.n = 2;
	fd.argc = argc;
	fd.input = open(argv[1], O_RDONLY);
	fd.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd.input < 0)
	{
		ft_putstr_fd_count("No such file or directory\n", 2);
		exit_error(0);
	}
	check_for_error(pipe(fd.io));
	while (fd.n < argc - 1)
	{
		child.pid = fork();
		check_for_error(child.pid);
		if (child.pid == 0)
			child_process(&fd, envp, argv[fd.n]);
		waitpid(child.pid, &child.status, 0);	
		close(fd.input);
		close(fd.output);
		fd.n++;
	}
	end_fd_close(&fd);
	if (WIFEXITED(child.status) != 0)
		exit(WEXITSTATUS(child.status));
	exit(0);
}
