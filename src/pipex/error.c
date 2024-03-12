/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:39:19 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 13:26:57 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error_message(char *file)
{
	char	*message;

	ft_putstr_fd("minishell: ", 2);
	message = ft_strdup(strerror(errno));
	if (message)
		ft_putstr_fd(message, 2);
	else
		ft_putstr_fd("error allocating error_message", 2);
	if (file)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
	}
	ft_putstr_fd("\n", 2);
	if (message)
		free(message);
}

void	cmd_not_found(t_pipex *pipex, int i)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(pipex->cmds[i].args[0], 2);
	ft_putstr_fd("\n", 2);
	pipex->cmds[i].found = false;
}
