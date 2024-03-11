/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:46 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/11 18:00:03 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exec(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;
	int		status;
	pid_t	pid;

	cmds = ft_split(cmd, " ");
	path = ft_path(cmds[0], envp);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmds, envp) == -1)
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putendl_fd(cmds[0], 2);
			ft_free_arr(cmds);
			exit(0);
		}
	}
	else if (pid < 0)
		print_error("fork failed");
	else
		waitpid(pid, &status, 0);
}

void	here_doc_in(char **argv, int *fd)
{
	char *ret;

	close(fd[0]);
	while (1)
	{
		printf("> ");
		ret = readline("");
		if (!ret)
			continue;
		if (strcmp(ret, argv[2]) == 0)
		{
			free(ret);
			close(fd[1]);
			exit(0);
		}
		free(ret);
	}
}

void	here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		here_doc_in(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

void	pipex_bonus(t_mini *mini, int argc, char **argv, char **envp)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		i = 3;
		fd_out = ft_open(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		if (mini->flag_infile == FALSE)
			fd_in = STDIN_FILENO;
		else
			fd_in = ft_open(argv[1], 0);
		if (mini->flag_outfile == FALSE)
			fd_out = STDOUT_FILENO;
		else
			fd_out = ft_open(argv[argc - 1], 1); //Cambiar a outfile
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		ft_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	ft_exec(argv[argc - 2], envp);
}
