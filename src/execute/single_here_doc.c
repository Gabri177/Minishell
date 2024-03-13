/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:18:34 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 03:42:57 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**parse_single_here_doc(t_mini *mini)
{
	char	**here_doc;

	here_doc = malloc((4) * sizeof(char *));
	if (here_doc == NULL)
		return (NULL);
	here_doc[0] = ft_strdup("./minishell");
	here_doc[1] = ft_strdup(mini->infile[arry_count(mini->infile) - 1]);
	here_doc[2] = ft_strdup(mini->commands[0]);
	here_doc[3] = NULL;
	return (here_doc);
}


void	here_doc_producer(char *delimiter)
{
	char	*input;

	while ((input = readline("minishell > ")) != NULL)
	{
		if (ft_strcmp(input, delimiter) == 0)
		{
			free(input);
			break ;
		}
		free(input);
	}
}

void	here_doc_consumer(char *cmd)
{
	int		fd[2];
	pid_t	pid;
	char	buffer[1024];
	ssize_t	bytes_read;

	bytes_read = 0;
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execvp(cmd, (char *[]){cmd, NULL});
		exit(1);
	}
	else
	{
		close(fd[1]);
		while ((bytes_read = read(fd[0], buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, bytes_read);
		close(fd[0]);
		wait(NULL);
	}
}

// This function can only take ./minishell DELIMITER COMAND
int	single_here_doc(int argc, char **argv)
{
	char	*delimiter;
	char	*cmd;

	if (argc != 3)
	{
		printf("Usage: ./minishell 'delimiter' 'command'\n");
		exit(1);
	}
	delimiter = argv[1];
	cmd = argv[2];
	here_doc_producer(delimiter);
	here_doc_consumer(cmd);
	return (0);
}
