/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/05 15:02:07 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**delete_env(t_mini	*mini, char *variable)
{
	char	**temp;
	char	**next;
	int		len_to_equal;
	//int	i;

	temp = mini->envp;
	len_to_equal = 0;
	//i = 0;
	while (variable[len_to_equal] != '=' && variable[len_to_equal])
		len_to_equal++;
	while (*temp != NULL)
	{
		if (ft_strncmp(*temp, variable, len_to_equal) == 0)
		{
			next = temp + 1;
			while (*next != NULL)
			{
				*temp = *next;
				temp = next;
				++next;
			}
			*temp = NULL;
			break;
		}
		++temp;
		}
	temp = mini->envp;
	return (mini->envp);
}

/*int	ft_unset(t_mini	*mini)
{
	delet_env(mini, mini->commands[0]); //Una vez gao haya terminado el parseo poner aquí la función delete_env 
	//usando directamente mini->command[0] y eliminar delete_env
	retrurn (TRUE);
}*/

/*int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	argc = 0;
	init_mini(&mini, argv, envp);
	while (mini.envp[argc])
	{
		printf("%s\n\n", mini.envp[argc]);
		argc++;
	}
	delete_env(&mini, "PWD=Home");
	argc = 0;
	while (mini.envp[argc])
	{
		printf("%s\n", mini.envp[argc]);
		argc++;
	}
	system ("leaks -q minishell");
	return (0);
}*/