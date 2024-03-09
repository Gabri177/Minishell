/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/09 16:59:59 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cd_no_arg(t_mini *mini)
{
	char	*home;
	char	*variable;
	char	*pwd;
	char	*oldpwd;

	if (hash_grep(mini->hash_env, "HOME") == NULL)
		return (print_error("cd: HOME not set"));
	else
	{
		home = ft_substr(hash_grep(mini->hash_env, "HOME"), 5, ft_strlen(hash_grep(mini->hash_env, "HOME")));
		pwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 4, ft_strlen(hash_grep(mini->hash_env, "PWD")));
		variable = ft_strjoin("PWD=", home);
		oldpwd = ft_strjoin("OLDPWD=", pwd);
		ft_export(mini, variable);
		ft_export(mini, oldpwd);
		free(home);
		free (variable);
		free(oldpwd);
		free(pwd);
	}
	return (EXIT_SUCCESS);
}

static int	cd_dot_dot(t_mini *mini)
{
	char	*oldpwd;
	char	*newpwd;
	char	*newoldpwd;

	oldpwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 4, ft_strlen(hash_grep(mini->hash_env, "PWD")));
	newpwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 0, ft_strrchrlen(hash_grep(mini->hash_env, "PWD"), '/'));
	newoldpwd = ft_strjoin("OLDPWD=", oldpwd);
	ft_export(mini, newpwd);
	ft_export(mini, newoldpwd);
	free (oldpwd);
	free(newpwd);
	free(newoldpwd);
	return(EXIT_FAILURE);
}
/*static int	cd_word(t_mini *mini, char *argument)
{
	char	*pwd;
	char	*oldpwd_env;
	//char	*pwd_with_slash;
	char	*pwd_env;
	(void)argument;

	if (access(argument, F_OK) == -1)
		return (print_error("folder doesn't exist"));
	if (chdir(argument) == -1)
		return(print_error("chdir failed"));
	//pwd_env = getcwd(NULL, 0);
	//if (!pwd_env)
	//	return (print_error("getcwd failed"));
	pwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 4, ft_strlen(hash_grep(mini->hash_env, "PWD")));
	oldpwd_env = ft_strjoin("OLDPWD=", pwd);
	ft_export(mini, oldpwd_env);
	ft_export(mini, pwd_env);
	free(pwd);
	free(oldpwd_env);
	return (EXIT_SUCCESS);
}*/


int	ft_cd(t_mini *mini, char *argument)
{
	if (hash_grep(mini->hash_env, "OLDPWD") == NULL)
		hash_push(mini->hash_env, "OLDPWD=", ft_substr(hash_grep(mini->hash_env, "PWD"), 4, ft_strlen(hash_grep(mini->hash_env, "PWD"))));
	if (argument == NULL || !*argument || ft_strcmp(argument, "哈") == 0)
		return (cd_no_arg(mini));
	else if (ft_strcmp(argument, "..") == 0)
		return(cd_dot_dot(mini));
	else if (argument[0] == '.')
		return (EXIT_SUCCESS);
	//else
	//	return(cd_word(mini, argument));
	return (EXIT_SUCCESS);
}

/*int	main(int argc, char **argv, char **envp)
{
	t_mini 	mini;
	argc = 0;
	argv = NULL;
	init_env(&mini, envp);
	hash_display(*mini.hash_env);
	ft_cd(&mini, NULL);
	hash_display(*mini.hash_env);
	hash_destory(mini.hash_env);
	system("leaks -q minishell");
	return (0);
}*/