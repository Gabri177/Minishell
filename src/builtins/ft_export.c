/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 07:57:07 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_have_var(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (TRUE);
		str ++;
	}
	return (FALSE);
}

int	ft_export(t_mini *mini, char *variable)
{
	int		len_to_equal;
	char	*key;

	if (!is_have_var (variable))
		return (EXIT_SUCCESS);
	len_to_equal = ft_strchrlen(variable, '=');
	key = ft_substr(variable, 0, len_to_equal);
	hash_push(mini->hash_env, key, variable);
	free(key);
	return (EXIT_SUCCESS);
}
