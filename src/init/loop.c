/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:45:16 by javgao            #+#    #+#             */
/*   Updated: 2024/03/06 20:23:48 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void shell_loop(t_mini *mini) 
{
	char *line;

	while (1) 
	{
		line = readline("mi_shell> ");
		if (!line)
			break ;
		if (*line)
		{
			add_history(line);
			mini->arg_ori = arg_abordar (line);
			free(line);
			printf ("original :\n");
			arry_display (mini->arg_ori);
			mini->outfile = args_to_outfile (&mini->arg_ori);
			printf ("outfile :\n");
			arry_display (mini->outfile);
			mini->commands = args_to_cmds (&mini->arg_ori);
			printf ("command :\n");
			arry_display (mini->commands);
			mini->args = args_to_args (&mini->arg_ori);
		}
		// Aquí se pueden añadir códigos para procesar el comando
		
	}
}

/*int main() {
    // Inicialización de la biblioteca readline
    rl_on_new_line();
    shell_loop(); // Ejecutar el bucle del shell
    return 0;
}*/