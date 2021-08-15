/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:11:39 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 16:24:10 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exit_bonus(int i)
{
	if (i == 1)
		ft_putstr_fd("Error: wrong cmd \"\"\n", 2);
	else if (i == 2)
		ft_putstr_fd("Usage: ./pipex_bonus file1 cmd1 ... cmdN file2\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error: can't make pipe\n", 2);
	exit(1);
}
