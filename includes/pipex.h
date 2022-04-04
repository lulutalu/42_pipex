/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:42:21 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/04 12:37:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
 * Default Library
*/

# include "pipex.h"
# include "utils.h"
# include "get_next_line.h"

/*
 * Authorized Function Library's
*/

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

/*
 * Error Messages Macro
*/

# define N_ARGS "\e[1;91mNumber of arguments incorrect\n\e[0m"
# define FD_IN 1
# define FD_OU 0

/*
 * Structures
*/

typedef struct s_pid
{
	pid_t	pid;
	int		status;
}				t_pid;

typedef struct s_fd
{
	int		io[2];
	int		input;
	int		output;
	int		outfile;
}				t_fd;

typedef struct s_pars
{
	int		i;
	char	**split;
	char	**exec;
	char	**arg;
	char	*cmd;
	char	*path;
	char	*temp;
}				t_pars;

/*
 * Errors and Memory Functions
*/

void	exit_error(int status);
void	free_tab(void **mem);
void	check_for_error(int value);
void	number_arg_check(int argc);

/*
 * File descriptor opening and closing
*/

void	end_fd_close(t_fd *fd);
void	start_fd_open(t_fd *fd, char *in, char *out);

/*
 * Fork Functions
*/

void	first_child(t_fd *fd, t_pars *pars, char **envp, char *cmd);
void	scnd_child(t_fd *fd, t_pars *pars, char **envp, char *cmd);

/*
 * Parsing Functions
*/

int		parsing_env(t_pars *pars, char **envp);

#endif
