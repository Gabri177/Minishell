/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:33:33 by javgao            #+#    #+#             */
/*   Updated: 2024/03/06 20:11:16 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	if (argc > 1)
		return(print_error("More than one argument"));
	init_mini (&mini, envp);
	rl_on_new_line();
	shell_loop(&mini);
	(void)argv;
	return (0);
} 
