/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds_and_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:35 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 14:06:59 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**check_cmds_and_args(t_mini *mini)
{
	char	**cmds_and_args;
	int		i;
	int		arc;

	i = 2;
	arc = 0;
	cmds_and_args = malloc((mini->argc + 3) * sizeof(char *));
	if (cmds_and_args == NULL)
		return (NULL);
	cmds_and_args[0] = ft_strdup("./minishell");
	if (mini->infile == NULL)
		cmds_and_args[1] = ft_strdup("./Libft/ft_printf/.infile");
	else
		cmds_and_args[0] = ft_strdup(mini->infile[1]);
	while (arc < mini->argc)
	{
		cmds_and_args[i] = strdup(mini->cmds_and_args[arc]);
		i++;
		arc++;
	}
	if (mini->outfile == NULL)
		cmds_and_args[i] =ft_strdup("./Libft/ft_printf/.outfile");
	else
		cmds_and_args[i] = ft_strdup(mini->outfile[1]);
	cmds_and_args[i + 1] = NULL;
	return (cmds_and_args);
}
