/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:56 by javgao            #+#    #+#             */
/*   Updated: 2024/03/08 14:15:25 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_execute(t_mini *mini)
{
	int i;
	int	pipe_found;

	i = 0;
	pipe_found = 0;
	while (mini->commands[i])
	{
		if (mini->commands[i][0] == '|')
		{
			printf("PIPEXXXX: De momento estoy con single command ya mañana pipex\n\n\n");
			//Gestionar el pipex
			pipe_found = 1;
		}
		i++;
	}
	if (!pipe_found)
	{
		single_command(mini);
		//printf("Single Command\n\n\n\n\n");
	}
	return (EXIT_SUCCESS);
}