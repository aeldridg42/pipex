/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:07:01 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 16:49:42 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(int i)
{
	if (i == 1)
		ft_putstr_fd("Can't make pipe:(\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error: wrong cmd - \"\"\n", 2);
	else if (i == 3)
		ft_putstr_fd("Can't find path:(\n", 2);
	else if (i == 4)
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	exit(1);
}
