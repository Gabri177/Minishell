/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/08 22:59:12 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/hash.h"

int	ft_unset(t_mini	*mini, char *variable)
{
	hash_del(mini->hash_env, variable);
	return (TRUE);
}

/*int	main(int argc, char **argv, char **envp)			//Tiene leaks
{
	t_mini	mini;
	argc = 0;
	argv = NULL;
	init_env(&mini, envp);
	hash_display(*mini.hash_env);	
	ft_unset(&mini, "PWD");
	hash_display(*mini.hash_env);
	hash_destory(mini.hash_env);
	system ("leaks -q minishell");
	return (0);
}*/