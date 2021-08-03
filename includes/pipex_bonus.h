/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:23:52 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/03 13:40:01 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex {
	int				i;
	int				fd[2];
	int				start;
	int				argc;
	int				**pipe_fd;
	char			**paths;
	char			**cmd;
	char			*tmp;
}					t_pipex;

int		init_b(t_pipex *pipex, char **envp, char **argv, int argc);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*strjoin_free(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	process(t_pipex *pipex, char **argv, char **envp);
void	process2(t_pipex *pipex, char **argv, char **envp);
void	process3(t_pipex *pipex, char **argv, char **envp);
void	ft_freedom_bonus(t_pipex *pipex);

#endif