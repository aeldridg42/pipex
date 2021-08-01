/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:06:37 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 16:54:11 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex {
	int				fd[2];
	int				pipe_fd[2];
	char			**paths;
	char			*cmd1;
	char			*cmd2;
	char			**cmd1s;
	char			**cmd2s;
	char			*tmp;
}					t_pipex;

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*strjoin_free(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	init(t_pipex *pipex, char **argv, char **envp);
void	firstproc(t_pipex *pipex, char **envp);
void	secondproc(t_pipex *pipex, char **envp);
void	ft_freedom(t_pipex *pipex);

#endif