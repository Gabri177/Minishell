/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds_and_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:35 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 13:13:20 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*static char *add_infile(t_mini *mini)
{
	char *infile;
	
	if (mini->flag_infile == TRUE)
	{
		printf("entra infile");
		infile = ft_strdup(mini->infile[1]); //Ver como me lo manda gao y ver que poner excatamente
		if (infile == NULL)
			return (NULL);
	}
	else
	{
		infile = ft_strdup(INFILE);
		if (infile == NULL)
			return (NULL);
	}
	return (infile);
}

static char *add_outfile(t_mini *mini)
{
	char *outfile;
	
	if (mini->flag_outfile == TRUE)
	{
		printf("entra outfile");
		outfile = ft_strdup(mini->outfile[1]); //Ver como me lo manda gao y ver que poner excatamente
		if (outfile == NULL)
			return (NULL);
	}
	else
	{
		outfile = ft_strdup(OUTFILE);
		if (outfile == NULL)
			return (NULL);
	}
	return (outfile);
}*/

char	**check_cmds_and_args(t_mini *mini)
{
	char	**cmds_and_args;
	int		i;
	int		arc;

	i = 1;
	arc = 0;
	cmds_and_args = malloc((mini->argc + 3) * sizeof(char *));
	if (cmds_and_args == NULL)
		return (NULL);
	if (mini->infile == NULL)
		cmds_and_args[0] = ft_strdup(INFILE);
	else
		cmds_and_args[0] = ft_strdup(mini->infile[1]);
	while (arc < mini->argc)
	{
		cmds_and_args[i] = strdup(mini->cmds_and_args[arc]);
		i++;
		arc++;
	}
	if (mini->outfile == NULL)
		cmds_and_args[i] =ft_strdup(OUTFILE);
	else
		cmds_and_args[i] = ft_strdup(mini->outfile[1]);
	cmds_and_args[i + 1] = NULL;
	return (cmds_and_args);
}
