/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_and_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:17:11 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 12:43:32 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*merge_cmd_args(char *first, char *second)
{
	char	*tem;
	char	*new;

	tem = ft_strjoin (first, " ");
	new = ft_strjoin (tem, second);
	free (tem);
	//printf ("cur:%s\n", new);
	return (new);
}

char	**args_to_cmds_args(char **args)
{
	char	**new;
	int		i;
	char	*tem;

	i = 0;
	new = NULL;
	tem = NULL;
	if (!args)
		return (NULL);
	while (args[i])
	{
		if (args[i] && args[i + 1] && !is_strsame (args[i + 1], "|"))
		{
			if (!tem)
				tem = merge_cmd_args (args[i], args[i + 1]);
			else
				tem = merge_cmd_args (tem, args[i + 1]);
		}
		else if (args[i] && (is_strsame (args[i + 1], "|") || !args[i + 1]))
		{
			if (tem)
			{
				merge_cmd_args (tem, args[i]);
				arry_add (&new, tem);
			}
			else
				arry_add (&new, args[i]);
			tem = NULL;
			i ++;
			if (!args[i])
				break ;
		}
		i ++;
	}
	return (new);
}
