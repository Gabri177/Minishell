/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/05 17:50:37 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*int	modify_env(t_mini *mini)
{
	
}*/

int	add_env(t_mini *mini, char	*variable)
{
	char	**temp;
	int		len;
	int		i;

	temp = mini->envp;
	len = 0;
	i = 0;
	while (mini->envp[i])
		len++;
	temp = (char **) malloc (len + 1);
	if (temp == NULL)
		return (print_error("Malloc failed on add_env"));
	while (i < len + 1)
	{
		temp[i] = ft_strdup(mini->envp[i]);
		if (temp[i] == NULL)
		return print_error("ft_strdup failed on add_env");
		i++;
	}
	temp[len] = ft_strdup(variable);
	temp[len + 1] = NULL;
	mini->envp = temp;
	return (TRUE);
}

int check_if_env_exist(t_mini *mini, char *variable)
{
	int	i;
	int	len_to_equal;

	i = 0;
	len_to_equal = 0;
	while (variable[len_to_equal] != '=' && variable[len_to_equal])
		len_to_equal++;
	while (mini->envp[i])
	{
		if (ft_strncmp(variable, mini->envp[i], len_to_equal) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/*int	ft_export(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_if_env_exist(mini, mini->commands[0]) == TRUE)
	{
		modift_env();
	}
	else
	{
		add_env(mini);
	}
		
}*/

/*int main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	argc = 0;
	init_mini(&mini, argv, envp);
	char variable[] = "PWD=home";
	add_env(&mini, variable);
	while (mini.envp[argc])
	{
		printf("%s\n", mini.envp[argc]);
		argc++;
	}
}*/
