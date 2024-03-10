/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 01:07:11 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *join_args(char *command, char **arguments)
{
	int		i;
	int		size;
	char	*full;
	char	*temp;

	i = 0;
	size = 0;
	while (arguments[size])
		size++;

	full = ft_strdup(command);
	while (i < size)
	{
		temp = ft_strjoin(full, " ");
		free(full);
		full = temp;
		temp = ft_strjoin(full, arguments[i]);
		free(full);
		full = temp;
		i++;
	}
	return (full);
}

static int	num_args(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i] != '\0' && ft_strcmp(arguments[i], "哈") != 0)
		i++;
	return (i);
}

void	not_builtin(char *command, char **arguments, t_mini *mini, int flag)
{
	char	*full;
	char	**envp;
	int		num_arg;

	envp = hash_to_arry(mini->hash_env);
	num_arg = num_args(arguments);
	if (num_arg >= 1)
	{
		full = join_args(command, arguments);
		ft_exec_single(full, envp);
	}
	else
		ft_exec_single(command, envp);
	free(envp);
	(void)flag;
}

/*int	main(int argc, char **argv, char **envp)
{
	t_mini mini;
	argc = 0;
	argv = NULL;
	//char *arr[7] = { "hola", "paco", "hola", "paco", "hola", "paco", NULL };
	init_mini(&mini, envp);
	not_builtin("ls", NULL, &mini, SINGLE);
	system("leaks -q minishell");
	return (0);
}*/
