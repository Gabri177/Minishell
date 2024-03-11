/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:27:04 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 03:55:47 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*char	**arr_full_command(t_mini *mini)
{
	int		i;
	char	**full;

	i = 0;
	if (!mini->commands)
		return (NULL);
	while (mini->commands[mini->argc + i])
	{
		if (mini->commands[mini->argc][0] == '|')
			i++;
		else
			mini->argc++;
	}
	printf("%d", mini->argc);
	i = 0;
	full = malloc (mini->argc + 1); 
	while (i < mini->argc)
	{
		full[i] = ft_strdup(join_args(mini->commands[i], mini->args[i]));
		if (full[i] == NULL)
		{
			print_error("Malloc failed");
			return (NULL);
		}
		i++;
	}
	full[i] = NULL;
	return (full);			//borrarr
}*/