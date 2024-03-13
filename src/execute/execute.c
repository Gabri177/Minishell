/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:56 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 04:56:26 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_execute(t_mini *mini)
{
	int		i;
	int		pipe_found;
	char	**argv;
	char *arr[] = {"./minishell", "here_doc", "END", "ls", "wc -l", NULL};

	i = 0;
	pipe_found = 0;
	if (!mini->commands)
		return (EXIT_SUCCESS);
	while (mini->commands[i])
	{
		if (mini->commands[i][0] == '|')
		{
			mini->argc = arry_count (mini->cmds_and_args);
			argv = check_cmds_and_args(mini);
			int j = 0;
			while (argv[j])
			{
				printf("%s\n", argv[j]);
				j++;
			}
			pipex_bonus(mini, mini->argc + 3, arr, hash_to_arry(mini->hash_env));
			ft_free_arr(argv);
			pipe_found = 1;
		}
		i++;
	}
	if (!pipe_found)
		single_command(mini);
	return (EXIT_SUCCESS);
}
