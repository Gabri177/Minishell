/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:07:51 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 02:10:28 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	args_no_infile(char ***args, char **infile)
{
	int	i;

	i = 0;
	if (!*args || !infile || !*infile)
		return ;
	while (infile[i])
	{
		arry_del (args, arry_get_index (*args, infile[i]));
		i ++;
	}
}

// no olvidas liberar new cuando terminar usandolo
char	**args_to_infile(char ***args)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	if (!*args || !**args)
		return (new);
	while ((*args)[i])
	{
		if (is_strsame ("<", (*args)[i]))
		{
			arry_add (&new, "<");
			if ((*args)[i + 1])
			{
				arry_add (&new, (*args)[i + 1]);
				i ++;
			}
		}
		else if (is_strsame ("<<", (*args)[i]))
		{
			arry_add (&new, "<<");
			if ((*args)[i + 1])
			{
				arry_add (&new, (*args)[i + 1]);
				i ++;
			}
		}
		i ++;
	}
	args_no_infile (args, new);
	return (new);
}
