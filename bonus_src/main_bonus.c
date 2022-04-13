/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/13 15:51:01 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	char	*buf;
	char	*here_doc;
	char	*limiter;
//	int		;

	if (argc < 5)
	{
		ft_putstr_fd_count(N_ARGS, 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		limiter = ft_strjoin(argv[2], "\n");
		here_doc = ft_calloc(1, sizeof(char));
		buf = ft_calloc(1, sizeof(char));
		fd.infile = open("temp", O_RDWR | O_CREAT | O_APPEND, 0644);
		fd.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		while (buf != NULL)
		{
			ft_putstr_fd_count("heredoc> ", 1);
			buf = get_next_line(0);
			if (ft_strncmp(buf, limiter, ft_strlen(buf)) == 0)
			{
				ft_putstr_fd_count(here_doc, fd.infile);
				exit(0);
			}
			here_doc = ft_dyn_strjoin(here_doc, buf);
		}
	}
	else
	{
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
	}
	end_fd_close(&fd);
	exit(0);
}
