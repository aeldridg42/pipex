/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:03:00 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 16:57:04 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	findpath(t_pipex *pipex, char **envp, int i2)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex->paths[i])
	{
		if (pipex->tmp)
			free(pipex->tmp);
		if (i2)
		{
			tmp = ft_strjoin(pipex->paths[i++], "/");
			pipex->tmp = ft_strjoin(tmp, pipex->cmd1s[0]);
			free(tmp);
			if (access(pipex->tmp, X_OK) == 0)
				execve(pipex->tmp, pipex->cmd1s, envp);
		}
		else
		{
			tmp = ft_strjoin(pipex->paths[i++], "/");
			pipex->tmp = ft_strjoin(tmp, pipex->cmd2s[0]);
			free(tmp);
			if (access(pipex->tmp, X_OK) == 0)
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
	ft_putstr_fd("Error: wrong cmd - \"", 2);
	ft_putstr_fd(pipex->cmd1s[0], 2);
	write(2, "\"\n", 2);
	ft_freedom(pipex);
	exit (1);
}

void	secondproc(t_pipex *pipex, char **envp)
{
	dup2(pipex->pipe_fd[0], 0);
	dup2(pipex->fd[1], 1);
	findpath(pipex, envp, 0);
	close(pipex->pipe_fd[0]);
	close(pipex->fd[1]);
	ft_putstr_fd("Error: wrong cmd - \"", 2);
	ft_putstr_fd(pipex->cmd2s[0], 2);
	write(2, "\"\n", 2);
	ft_freedom(pipex);
	exit (1);
}
