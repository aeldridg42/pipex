#include "includes/pipex_bonus.h"

static void	findpath(char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		pipex->tmp = ft_strjoin(pipex->paths[i++], "/");
		pipex->tmp = strjoin_free(pipex->tmp, pipex->cmd[0]);
		free(pipex->tmp);
		if (access(pipex->tmp, X_OK) == 0)
			execve(pipex->tmp, pipex->cmd, envp);
	}
	ft_putstr_fd("Wrong cmd\n", 2);
	exit (1);
}

static void pathinit(t_pipex *pipex, char **envp)
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

int initb(t_pipex *pipex, char **envp, char **argv, int argc)
{
	int i;

	i = 0;
	pipex->fd[0] = open(argv[1], O_RDONLY);
	pipex->fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	pipex->start = 2;
	pipex->pipe_fd = (int **)malloc(sizeof(int *) * (argc - 4));
	while (i < argc - 4)
		pipex->pipe_fd[i++] = malloc(sizeof(int) * 2);
	pathinit(pipex, envp);
	return (0);
}

void dirtywork(t_pipex *pipex, int i, char **argv, char **envp)
{
	close(pipex->pipe_fd[i][0]);
	dup2(pipex->fd[0], 0);
	dup2(pipex->pipe_fd[i][1], 1);
	pipex->cmd = ft_split(argv[pipex->start], ' ');
	findpath(envp, pipex);
}

void dirtywork2(t_pipex *pipex, int i, char **argv, char **envp)
{
	close(pipex->pipe_fd[i][0]);
	dup2(pipex->pipe_fd[i - 1][0], 0);
	dup2(pipex->pipe_fd[i][1], 1);
	pipex->cmd = ft_split(argv[pipex->start], ' ');
	findpath(envp, pipex);
}

void dirtywork3(t_pipex *pipex, int i, char **argv, char **envp)
{
	close(pipex->pipe_fd[i - 1][1]);
	dup2(pipex->pipe_fd[i - 1][0], 0);
	dup2(pipex->fd[1], 1);
	pipex->cmd = ft_split(argv[pipex->start], ' ');
	findpath(envp, pipex);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		pid;
	int		i;

	i = initb(&pipex, envp, argv, argc);
	pipe(pipex.pipe_fd[i]);
	pid = fork();
	if (!pid)
		dirtywork(&pipex, i, argv, envp);
	else
	{
		close(pipex.fd[0]);
		close(pipex.pipe_fd[i++][1]);
		wait(0);
		pipex.start++;
		while (i < argc - 4)
		{
			pipe(pipex.pipe_fd[i]);
			pid = fork();
			if (!pid)
				dirtywork2(&pipex, i, argv, envp);
			pipex.start++;
			close(pipex.pipe_fd[i++][1]);
			wait(0);
		}
		pid = fork();
		if (!pid)
			dirtywork3(&pipex, i, argv, envp);
		close(pipex.pipe_fd[i - 1][0]);
		close(pipex.fd[1]);
		wait(0);
	}
	return (0);
}

