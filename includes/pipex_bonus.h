/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azat <azat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:23:52 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/02 21:30:42 by azat             ###   ########.fr       */
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
    int             start;
	int				**pipe_fd;
	char			**paths;
	char            **cmd;
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