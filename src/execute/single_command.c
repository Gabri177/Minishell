/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/07 12:16:29 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	single_command(t_mini *mini)
{
	printf(".%s.\n", mini->commands[0]);
	if (is_builtin(mini->commands[0], mini) == TRUE)
	{
		//exec_builtin();
		//Gestionar builtin, borrar corchetes. 
		printf("es builtin\n\n\n\n");
	}
	else
	{
		printf("Gestionar no  builtin\n\n\n");
		//Gestionar no builtin, return FALSE si no existe. Si pone fyigfdhgkjghdskjgd por ejemplo
	}
	return (TRUE);
}