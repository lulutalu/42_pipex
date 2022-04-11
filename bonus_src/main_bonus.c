/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/12 00:12:38 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;

	if (argc < 5)
	{
		ft_putstr_fd_count(N_ARGS, 2);
		exit(1);
	}
	fd.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	fd.infile = open(argv[1], O_RDONLY);
	if (fd.infile < 0)
	{
		ft_putstr_fd_count("No such file or directory\n", 2);
		exit(1);
	}
	fd.ncmd = argc - 3;
	fd.npipe = fd.ncmd - 1;
	fd.icmd = 2;
	while (fd.icmd < (fd.ncmd + 2))
	{
		child_process(&fd, envp, argv[fd.icmd]);
		fd.icmd++;
	}
	end_fd_close(&fd);
	exit(0);
}
