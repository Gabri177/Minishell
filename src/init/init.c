/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:34:33 by javgao            #+#    #+#             */
/*   Updated: 2024/03/03 19:11:53 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/init.h"

void	init_mini(t_mini *mini, int argc, char **argv, char **envp)
{
	mini->argc = argc;
	mini->argv = argv;
	mini->envp = envp;
	mini->pwd = NULL;
	mini->old_pwd;
	mini->paths = NULL;
	mini->infile = NULL;
	mini->outfile = NULL;
	mini->commands = NULL;
	mini->args = NULL;
}

