/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:40:16 by javgao            #+#    #+#             */
/*   Updated: 2024/03/05 23:01:50 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	args_no_outfile(char ***args, char **ofile)
{
	int	i;

	i = 0;
	while (ofile[i])
	{
		arry_del (args, arry_get_index (*args, ofile[i]));
		i ++;
	}
}

// no olvidas liberar new cuando terminar usandolo
char	**args_to_outfile(char ***args)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	while ((*args)[i])
	{
		if (is_strsame (">", (*args)[i]))
		{
			arry_add (&new, ">");
			if ((*args)[i + 1])
			{
				arry_add (&new, (*args)[i + 1]);
				i ++;
			}
		}
		else if (is_strsame (">>", (*args)[i]))
		{
			arry_add (&new, ">>");
			if ((*args)[i + 1])
			{
				arry_add (&new, (*args)[i + 1]);
				i ++;
			}
		}
		i ++;
	}
	args_no_outfile (args, new);
	return (new);
}
