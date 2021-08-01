/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:00:18 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 17:44:09 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	checkfd(int i)
{
	if (i < 0)
	{
		perror("Can't open file\n");
		exit (1);
	}
	if (read(i, 0, 0) < 0)
	{
		perror("Can't read file\n");
		exit (1);
	}
}

static void	searchpath(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		++i;
	if (!envp[i])
	{
		perror("Can't find path:(\n");
		exit (1);
	}
	pipex->paths = ft_split(envp[i] + 5, ':');
}

void	init(t_pipex *pipex, char **argv, char **envp)
{
	pipex->fd[0] = open(argv[1], O_RDONLY);
	checkfd(pipex->fd[0]);
	pipex->fd[1] = open(argv[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
	checkfd(pipex->fd[1]);
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("Can't make pipe:(\n");
		exit(1);
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		ft_putstr_fd("Wrong cmd\n", 2);
		exit(1);
	}
	pipex->cmd1 = ft_strdup(argv[2]);
	pipex->cmd2 = ft_strdup(argv[3]);
	pipex->cmd1s = ft_split(argv[2], ' ');
	pipex->cmd2s = ft_split(argv[3], ' ');
	searchpath(pipex, envp);
}
