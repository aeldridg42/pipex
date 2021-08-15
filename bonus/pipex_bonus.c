/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:22:54 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 16:19:58 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	mainprocess(t_pipex *pipex, char **argv, char **envp, int argc)
{
	int	pid;

	close(pipex->fd[0]);
	close(pipex->pipe_fd[pipex->i++][1]);
	wait(0);
	pipex->start++;
	while (pipex->i < argc - 4)
	{
		if (pipe(pipex->pipe_fd[pipex->i]) < 0)
			ft_exit_bonus(3);
		pid = fork();
		if (!pid)
			process2(pipex, argv, envp);
		pipex->start++;
		close(pipex->pipe_fd[pipex->i++][1]);
		wait(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		pid;

	if (argc < 5)
		ft_exit_bonus(2);
	pipex.i = init_b(&pipex, envp, argv, argc);
	if (pipe(pipex.pipe_fd[pipex.i]) < 0)
		ft_exit_bonus(3);
	pid = fork();
	if (!pid)
		process(&pipex, argv, envp);
	else
	{
		mainprocess(&pipex, argv, envp, argc);
		pid = fork();
		if (!pid)
			process3(&pipex, argv, envp);
		close(pipex.pipe_fd[pipex.i - 1][0]);
		close(pipex.fd[1]);
		wait(0);
	}
	ft_freedom_bonus(&pipex);
	return (0);
}
