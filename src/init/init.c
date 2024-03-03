/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:34:33 by javgao            #+#    #+#             */
/*   Updated: 2024/03/03 18:45:08 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/init.h"

void	init_proj(t_mini *proj, int argc, char **argv, char **envp)
{
	proj->argc = argc;
	proj->argv = argv;
	proj->envp = envp;
	proj->pwd = NULL;
	proj->old_pwd;
	proj->paths = NULL;
	proj->infile = NULL;
	proj->outfile = NULL;
	proj->commands = NULL;
	proj->args = NULL;
}

