/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:03:00 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 16:55:18 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	findpath(t_pipex *pipex, char **envp, int i2)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		if (i2)
		{
			pipex->tmp = ft_strjoin(pipex->paths[i++], "/");
			pipex->tmp = strjoin_free(pipex->tmp, pipex->cmd1s[0]);
			free(pipex->tmp);
			execve(pipex->tmp, pipex->cmd1s, envp);
		}
		else
		{
			pipex->tmp = ft_strjoin(pipex->paths[i++], "/");
			pipex->tmp = strjoin_free(pipex->tmp, pipex->cmd2s[0]);
			free(pipex->tmp);
			execve(pipex->tmp, pipex->cmd2s, envp);
		}
	}
}

void	firstproc(t_pipex *pipex, char **envp)
{
	dup2(pipex->pipe_fd[1], 1);
	dup2(pipex->fd[0], 0);
	findpath(pipex, envp, 1);
	close(pipex->pipe_fd[1]);
	close(pipex->fd[0]);
	ft_freedom(pipex);
	ft_putstr_fd("Wrong cmd1\n", 2);
	exit (1);
}

void	secondproc(t_pipex *pipex, char **envp)
{
	dup2(pipex->pipe_fd[0], 0);
	dup2(pipex->fd[1], 1);
	findpath(pipex, envp, 0);
	close(pipex->pipe_fd[0]);
	close(pipex->fd[1]);
	ft_freedom(pipex);
	ft_putstr_fd("Wrong cmd2\n", 2);
	exit (1);
}
