/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:06:25 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 16:55:01 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static void	forkproc(t_pipex *pipex, char **envp)
{
	int	id2;

	id2 = fork();
	if (id2)
	{
		close(pipex->fd[1]);
		close(pipex->pipe_fd[0]);
		firstproc(pipex, envp);
	}
	else
	{
		close(pipex->fd[0]);
		close(pipex->pipe_fd[1]);
		secondproc(pipex, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		id;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
		exit (0);
	}
	init(&pipex, argv, envp);
	id = fork();
	if (!id)
		forkproc(&pipex, envp);
	wait(NULL);
	ft_freedom(&pipex);
	return (0);
}
