/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:55:16 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 13:39:23 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_free(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		++i;
	}
	free(split);
}

void	ft_freedom_bonus(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->argc - 4)
		free (pipex->pipe_fd[i++]);
	free(pipex->pipe_fd);
	i = 0;
	if (pipex->tmp)
		free(pipex->tmp);
	if (pipex->cmd)
	{
		while (pipex->cmd[i])
			++i;
		ft_free(pipex->cmd, i);
	}
	i = 0;
	while (pipex->paths[i])
		++i;
	ft_free(pipex->paths, i);
}
