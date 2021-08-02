#include "includes/pipex.h"

static void	findpath(char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		pipex->tmp = ft_strjoin(pipex->paths[i++], "/");
		pipex->tmp = strjoin_free(pipex->tmp, pipex->cmd1s[0]);
		free(pipex->tmp);
		if (access(pipex->tmp, X_OK) == 0)
			execve(pipex->tmp, pipex->cmd1s, envp);
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

void cmdinit(char *argv, t_pipex *pipex)
{
	pipex->cmd1s = ft_split(argv, ' ');
}

void initb(t_pipex *pipex, char **envp, char **argv, int argc)
{
	pipex->fd[0] = open(argv[1], O_RDONLY);
	pipex->fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	pathinit(pipex, envp);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	pid_t  pid;
	int y = 0;
	int fd[argc - 3][2];
	int argd = 2;
	initb(&pipex, envp, argv, argc);
	pipe(fd[y]);
	pid = fork();
	if (!pid)
	{
		close(fd[y][0]);
		dup2(pipex.fd[0], 0);
		dup2(fd[y][1], 1);
		cmdinit(argv[argd], &pipex);
		findpath(envp, &pipex);
	}
	else
	{
		close(pipex.fd[0]);
		close(fd[y++][1]);
		wait(0);
		argd++;
		while (y < argc - 4)
		{
			pipe(fd[y]);
			pid = fork();
			if (!pid)
			{
				close(fd[y][0]);
				dup2(fd[y - 1][0], 0);
				dup2(fd[y][1], 1);
				cmdinit(argv[argd], &pipex);
				findpath(envp, &pipex);
			}
			argd++;
			close(fd[y++][1]);
			wait(0);
		}
		pid = fork();
		if (!pid)
		{
			close(fd[y - 1][1]);
			dup2(fd[y - 1][0], 0);
			dup2(pipex.fd[1], 1);
			cmdinit(argv[argd], &pipex);
			findpath(envp, &pipex);
		}
		close(fd[y - 1][0]);
		close(pipex.fd[1]);
		wait(0);
	}
	return (0);
}

