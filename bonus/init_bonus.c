/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:36:25 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 13:39:27 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

static void	pathinit(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		++i;
	if (!envp[i])
	{
		ft_putstr_fd("Can't find path:(\n", 2);
		exit (1);
	}
	pipex->paths = ft_split(envp[i] + 5, ':');
}

static void	puterror(void)
{
	ft_putstr_fd("Error: wrong cmd\n", 2);
	exit(1);
}

int	init_b(t_pipex *pipex, char **envp, char **argv, int argc)
{
	int	i;

	i = 0;
	pipex->argc = argc;
	pipex->fd[0] = open(argv[1], O_RDONLY);
	checkfd(pipex->fd[0]);
	pipex->fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	checkfd(pipex->fd[1]);
	pipex->tmp = NULL;
	while (argv[i])
	{
		if (argv[i][0])
			++i;
		else
			puterror();
	}
	i = 0;
	pipex->start = 2;
	pipex->pipe_fd = (int **)malloc(sizeof(int *) * (argc - 4));
	while (i < argc - 4)
		pipex->pipe_fd[i++] = (int *)malloc(sizeof(int) * 2);
	pathinit(pipex, envp);
	return (0);
}
