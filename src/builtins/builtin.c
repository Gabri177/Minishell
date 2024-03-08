/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:52 by javgao            #+#    #+#             */
/*   Updated: 2024/03/08 23:00:15 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		is_builtin(char *command, t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->is_builtin[i] != NULL)
	{
		if (ft_strcmp(command, mini->is_builtin[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	exec_builtin(char *command, char **arguments, t_mini *mini)
{ //Ver si tiene que ser ***args											Solo falta que gao haga el parseo bien
	if (ft_strcmp("echo", command) == 0)
		ft_echo(mini, arguments, FALSE);
	else if (ft_strcmp("echo -n", command) == 0)
		ft_echo(mini, arguments, TRUE);
	/*else if (ft_strcmp("cd", command) == 0)
		ft_cd(mini);*/
	else if (ft_strcmp("pwd", command) == 0)
		ft_pwd(mini);
	else if (ft_strcmp("export", command) == 0)
		ft_export(mini, mini->args[0][0]);
	else if (ft_strcmp("unset", command) == 0)
		ft_unset(mini, mini->args[0][0]);
	else if (ft_strcmp("env", command) == 0)
		ft_env(mini);
	/*else if (ft_strcmp("exit", command) == 0)
		ft_exit(mini);*/
}

/*
int main(int argc, char **argv, char **envp) //Borrar este main cuando entregemos 
{
	t_mini	mini;
	init_mini(&mini, argv, envp);
	if (argc < 0)
		printf ("Error\n");
	//init_builtin(&mini);
	if ((is_builtin("env", &mini) == 1))
		exec_builtin("env", &mini);
	system("leaks -q minishell");
	return (0);
}*/