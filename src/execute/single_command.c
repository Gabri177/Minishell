/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 00:21:19 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exec_single(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;
	int		status;

	cmds = ft_split(cmd, " ");
	path = ft_path(cmds[0], envp);
	pid_t pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmds, envp) == -1)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putendl_fd(cmds[0], 2);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		print_error("fork failed");
	else
		waitpid(pid, &status, 0);
	ft_free(cmds);
	free(path);
}
int	single_command(t_mini *mini)
{
	if (is_builtin(mini->commands[0], mini) == TRUE)
		exec_builtin(mini->commands[0], mini->args[0], mini);
	else
		not_builtin(mini->commands[0], mini->args[0], mini, SINGLE);
	return (TRUE);
}