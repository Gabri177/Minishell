/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/08 18:49:03 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	single_command(t_mini *mini)
{
	if (is_builtin(mini->commands[0], mini) == TRUE)
		exec_builtin(mini->commands[0], mini->args[0], mini);
	//else
	//	not_builtin(mini->commands[0], mini->args[0], mini, SINGLE);
	return (TRUE);
}