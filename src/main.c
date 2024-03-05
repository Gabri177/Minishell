/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:33:33 by javgao            #+#    #+#             */
/*   Updated: 2024/03/05 20:25:33 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/minishell.h"

int	main(int arc, char **argv, char **envp)
{
	t_mini	mini;

	//init_mini (&mini, arc, argv, envp);
	init_env(&mini, envp);
	(void)arc;
	(void)argv;
	(void)envp;
	printf("Compila la libft");
	return (0);
}
