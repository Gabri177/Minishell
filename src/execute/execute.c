/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:56 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 01:41:12 by javgao           ###   ########.fr       */
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
			printf("PIPEXXXX: ya mañana pipex\n\n\n");
			pipe_found = 1;
		}
		i++;
	}
	if (!pipe_found)
		single_command(mini);
	return (EXIT_SUCCESS);
}
