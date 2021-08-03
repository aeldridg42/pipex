/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:46:43 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 13:39:31 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	findpath(char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		if (pipex->tmp)
			free(pipex->tmp);
		pipex->tmp = ft_strjoin(pipex->paths[i++], "/");
		pipex->tmp = strjoin_free(pipex->tmp, pipex->cmd[0]);
		if (access(pipex->tmp, X_OK) == 0)
			execve(pipex->tmp, pipex->cmd, envp);
	}
	ft_putstr_fd("Error: wrong cmd\n", 2);
	ft_freedom_bonus(pipex);
	exit (1);
}

void	process(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe_fd[pipex->i][0]);
	dup2(pipex->fd[0], 0);
	dup2(pipex->pipe_fd[pipex->i][1], 1);
	pipex->cmd = ft_split(argv[pipex->start], ' ');
	findpath(envp, pipex);
}

void	process2(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe_fd[pipex->i][0]);
	dup2(pipex->pipe_fd[pipex->i - 1][0], 0);
	dup2(pipex->pipe_fd[pipex->i][1], 1);
	pipex->cmd = ft_split(argv[pipex->start], ' ');
	findpath(envp, pipex);
}

void	process3(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe_fd[pipex->i - 1][1]);
	dup2(pipex->pipe_fd[pipex->i - 1][0], 0);
	dup2(pipex->fd[1], 1);
	pipex->cmd = ft_split(argv[pipex->start], ' ');
	findpath(envp, pipex);
}
