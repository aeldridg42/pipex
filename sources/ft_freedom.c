/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:46:47 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 16:54:28 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	ft_freedom(t_pipex *pipex)
{
	int	i;

	i = 0;
	free(pipex->cmd1);
	free(pipex->cmd2);
	while (pipex->cmd1s[i])
		++i;
	ft_free(pipex->cmd1s, i);
	i = 0;
	while (pipex->cmd2s[i])
		++i;
	ft_free(pipex->cmd2s, i);
	i = 0;
	while (pipex->paths[i])
		++i;
	ft_free(pipex->paths, i);
}
