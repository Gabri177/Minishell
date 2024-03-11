/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:34:33 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 03:10:41 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_mini(t_mini *mini, char **envp)
{
	mini->line = NULL;
	mini->arg_ori = NULL;
	mini->paths = NULL; //Javi
	mini->infile = NULL; //Gao
	mini->outfile = NULL; //Gao
	mini->commands = NULL; //Gao
	mini->args = NULL; //Gao
	mini->flag_infile = FALSE;
	mini->flag_outfile = FALSE;
	init_builtin(mini);
	init_env(mini, envp);
}

void	init_builtin(t_mini *mini)
{
	mini->is_builtin[0] = "echo";
	mini->is_builtin[1] = "echo -n";
	mini->is_builtin[2] = "cd";
	mini->is_builtin[3] = "pwd";
	mini->is_builtin[4] = "export";
	mini->is_builtin[5] = "unset";
	mini->is_builtin[6] = "env";
	mini->is_builtin[7] = NULL;
}
void	init_env(t_mini *mini, char **envp)
{
	int	i;
	int	len_to_equal;
	char	*key;

	i = 0;
	len_to_equal = 0;
	mini->hash_env = hash_init();
	while(envp[i])
	{
		len_to_equal = ft_strchrlen(envp[i], '=');
		key = ft_substr(envp[i], 0, len_to_equal);
		hash_push(mini->hash_env, key, envp[i]);
		free (key);
		i++;
	}
}

void	welcom(void)
{
	printf(WELCOM1);
	printf(WELCOM2);
	printf(WELCOM3);
	printf(WELCOM4);
	printf(WELCOM5);
	printf(WELCOM6);
	printf(WELCOM7);
	printf(WELCOM8);
	printf(WELCOM9);
	printf("\033[0m\n");
}


/* void	init_reset(t_mini)
{
	
} */
