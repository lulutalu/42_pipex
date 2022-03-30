/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:40:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/30 19:19:11 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	parsing_env(t_pars *pars, char **envp)
{
	if (ft_strchr(pars->cmd, '{') != NULL)
	{
		pars->split = ft_split(pars->cmd, ' ');
		pars->arg = ft_calloc(3, sizeof(char **));
		pars->arg[0] = ft_strdup(pars->split[0]);
		pars->arg[1] = ft_substr(pars->cmd, ft_strlen(pars->arg[0]) + 1, ft_strlen(pars->cmd));
	}
	else
	{
		pars->split = ft_split(pars->cmd, ' ');
		pars->i = 0;
		while (pars->split[pars->i] != NULL)
			pars->i++;
		pars->arg = ft_calloc(pars->i + 1, sizeof(char **));
		pars->i = 0;
		while (pars->split[pars->i] != NULL)
		{
			pars->arg[pars->i] = ft_strdup(pars->split[pars->i]);
			pars->i++;
		}
	}
	free_tab((void **)pars->split);
	//////////////////////////////////////////////////////////////////////////
	pars->i = 0;
	while (ft_strnstr(envp[pars->i], "PATH=", 5) == NULL)
		pars->i++;
	pars->path = ft_substr(envp[pars->i], 5, ft_strlen(envp[pars->i]) - 5);
	pars->split = ft_split(pars->path, ':');
	free(pars->path);
	//////////////////////////////////////////////////////////////////////////
	pars->i = 0;
	while (pars->split[pars->i] != NULL)
	{
		pars->temp = ft_strjoin(pars->split[pars->i], "/");
		pars->path = ft_strjoin(pars->temp, pars->arg[0]);
		if (access(pars->path, X_OK) == 0)
		{
		/*	ft_putstr_fd_count(pars->path, 2);
			ft_putchar_fd_count('\n', 2);
			pars->i = 0;
			while (pars->arg[pars->i] != NULL)
			{
				ft_putstr_fd_count(pars->arg[pars->i++], 2);
				ft_putchar_fd_count('\n', 2);
			}*/
			execve(pars->path, pars->arg, envp);
			perror("Exec failed ");
		}
		pars->i++;
	}
	//////////////////////////////////////////////////////////////////////////
	perror("Exec failed ");
}
