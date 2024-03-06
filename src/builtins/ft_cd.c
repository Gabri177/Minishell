/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/06 12:46:56 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*int	cd_no_arg(t_mini *mini)
{
	if (hash_grep(mini->hash_env, "HOME") == NULL)
		return (print_error("cd: HOME not set"));
	else
	{
		
		ft_export();
	}
	return (EXIT_SUCCESS);
}

//void	cd_arg


int	ft_cd(t_mini *mini, char *argument)
{
	if (argument == NULL)
		return (cd_no_arg(mini));
	return (EXIT_SUCCESS);
}

//////////////////////////////////////////////////////////// cd should update PWD and OLD_PWD ENV esto lo haré con las funciones export

int	main(int argc, char **argv, char **envp)				//Con leaks
{
	t_mini 	mini;
	argc = 0;
	argv = NULL;
	init_env(&mini, envp);
	ft_pwd(&mini);
	system("leaks -q minishell");
	return (0);
}*/