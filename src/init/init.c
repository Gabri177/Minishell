/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:34:33 by javgao            #+#    #+#             */
/*   Updated: 2024/03/05 20:26:04 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_mini(t_mini *mini, char **argv, char **envp)
{
	mini->argv = argv;
	//mini->envp = envp;
	//mini->hash_env = hash_init(); 
	envp= NULL;
	mini->pwd = NULL; //Javi
	mini->old_pwd = NULL; //Javi
	mini->paths = NULL; //Javi
	mini->infile = NULL; //Gao
	mini->outfile = NULL; //Gao
	mini->commands = NULL; //Gao
	mini->args = NULL; //Gao
	init_builtin(mini);
}

void	init_builtin(t_mini *mini)
{
	mini->is_builtin[0] = "echo";
	mini->is_builtin[1] = "cd";
	mini->is_builtin[2] = "pwd";
	mini->is_builtin[3] = "export";
	mini->is_builtin[4] = "unset";
	mini->is_builtin[5] = "env";
	mini->is_builtin[6] = "exit";
	mini->is_builtin[7] = NULL;
}
void	init_env(t_mini *mini, char **envp)
{
	int	i;
	int	len_to_equal;
	char	*key;

	i = 0;
	len_to_equal = 0;
	mini->envp = envp;
	mini->hash_env = hash_init();
	while(envp[i])
	{
		len_to_equal = ft_strchrlen(envp[i], '=');
		key = ft_substr(envp[i], 0, len_to_equal);
		hash_push(mini->hash_env, key, envp[i]);
		i++;
	}
	hash_display(*mini->hash_env);
	hash_destory(mini->hash_env);
}
