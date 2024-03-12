/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:56 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 13:09:26 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_execute(t_mini *mini)
{
	int	i;
	int	pipe_found;

	i = 0;
	pipe_found = 0;
	if (!mini->commands)
		return (EXIT_SUCCESS);
	while (mini->commands[i])
	{
		if (mini->commands[i][0] == '|')
		{
			while (mini->cmds_and_args[mini->argc])
				mini->argc++;
			printf("\nmini->argc: %d\n", mini->argc);
			check_cmds_and_args(mini);
			//pipex_bonus(mini->argc, mini->cmds_and_args, hash_to_arry(mini->hash_env));
			pipe_found = 1;
		}
		i++;
	}
	if (!pipe_found)
		single_command(mini);
	return (EXIT_SUCCESS);
}
