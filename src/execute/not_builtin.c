/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/09 01:45:59 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*join_args(char *command, char **arguments)
{
	int i;
	int size;
	char *full;
	char *space;

	i = 0;
	size = 0;
	space = " ";
	while (arguments[size])
		size++;
	full = ft_strdup(command);
	while (i < size)
	{
		char *temp = ft_strjoin(full, space);
		free(full);
		full = temp;
		temp = ft_strjoin(full, arguments[i]);
		free(full);
		full = temp;
		i++;
	}
	return (full);
}

void	not_builtin(char *command, char **arguments, t_mini *mini, int flag, char **envp)
{
	//int	i;
	char *full;

	//i = 0;
	(void)flag;
	full = join_args(command, arguments);
	ft_exec(full, envp);
	//flag = 0;
	mini->arg_ori = NULL;
	free (full);
}

/*int	main(int argc, char **argv, char **envp)
{
	t_mini mini;
	argc = 0;
	argv = NULL;
	char *arr[7];
	arr[0] = NULL;
	arr[1] = "paco";
	arr[2] = "hola";
	arr[3] = "paco";
	arr[4] = "hola";
	arr[5] = "paco";
	arr[6] = NULL;
	init_mini(&mini, envp);
	not_builtin("ls", arr, &mini, SINGLE, envp);
	system("leaks -q minishell");
	return (0);
}*/