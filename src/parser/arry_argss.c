/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_argss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:34:09 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 04:00:22 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/* 
static char	***cmds_realloc(char ***cmds, int cmds_count)
{
	char	***new_cmds;
	int		i;

	i = 0;
	new_cmds = (char ***)malloc(sizeof(char **) * (cmds_count + 1));
	if (!new_cmds)
		return (NULL);
	while (i < cmds_count)
	{
		new_cmds[i] = cmds[i];
		i ++;
	}
	new_cmds[cmds_count] = NULL;
	free(cmds);
	return (new_cmds);
}

static char	**process_arg(char **args, int *i)
{
	char	**current_args;
	int		has_args;

	current_args = NULL;
	has_args = 0;
	while (args[*i] && !is_strsame(args[*i], "|"))
	{
		arry_add(&current_args, args[(*i)++]);
		has_args = 1;
	}
	if (!has_args)
		arry_add(&current_args, "哈");
	return (current_args);
}

static char	***cmds_add_arg(char ***cmds, char **arg, int *cmds_count)
{
	cmds = cmds_realloc(cmds, ++(*cmds_count));
	if (!cmds)
		return (NULL);
	cmds[*cmds_count - 1] = arg;
	return (cmds);
}

char	***args_to_args(char **args)
{
	char	***cmds;
	int		cmds_count;
	int		i;
	char 	**current_args;

	cmds = NULL;
	cmds_count = 0;
	i = 0;
	if (!args || !*args || !**args)
		return (NULL);
	cmds = (char ***)malloc(sizeof(char **));
	if (!cmds)
		return (NULL);
	cmds[0] = NULL;
	while (args[i])
	{
		current_args = process_arg(args, &i);
		cmds = cmds_add_arg(cmds, current_args, &cmds_count);
		if (!cmds)
			return (NULL);
		if (args[i])
			i++;
	}
	return (cmds);
}
 */