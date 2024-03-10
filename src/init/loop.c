/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:45:16 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 20:31:22 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void shell_loop(t_mini *mini) 
{
	char *line;

	while (1) 
	{
    	line = readline(PROMPT);
		//line = readline("minishell>");
		if (line == NULL || ft_exit(line) == TRUE)
		{
			if (line)
			{
				free(line);
				break ;
			}
			printf("\x1b[1;32mminishell\x1b[0m\x1b[1;36m > \x1b[0mexit");
			break ;
		}
		if (!*line)
			continue ;
		if (*line)
		{
			add_history(line);
			mini->arg_ori = arg_abordar (line);
			if (!mini->arg_ori)
				continue ;
			free(line);
			//arry_display (mini->arg_ori);
			mini->arg_ori = split_filter (mini->arg_ori, mini->hash_env);
			line = NULL;
			//printf ("original :\n");							//Imprime el parser
			//arry_display (mini->arg_ori);							//Imprime el parser
			mini->outfile = args_to_outfile (&mini->arg_ori);
			//printf ("outfile :\n");							//Imprime el parser
			//arry_display (mini->outfile);							//Imprime el parser
			mini->commands = args_to_cmds (&mini->arg_ori);
			//printf ("command :\n");							//Imprime el parser
			//arry_display (mini->commands);							//Imprime el parser
			//arry_display (mini->arg_ori);							//Imprime el parser
			mini->args = args_to_args (mini->arg_ori);
			//printf ("ARGSSSSSSS :\n");							//Imprime el parser
			//arry_display (*mini->args);							//Imprime el parser
		}
		// Aquí se pueden añadir códigos para procesar el comando
		ft_execute(mini);
		//Clean
		arry_destory (mini->arg_ori);
		mini->arg_ori = NULL;
		arry_destory (mini->outfile);
		mini->outfile = NULL;
		arry_destory (mini->commands);
		mini->commands = NULL;
		argss_destory (mini->args);
		mini->args = NULL;
	}
}

/*int main() {
    // Inicialización de la biblioteca readline
    rl_on_new_line();
    shell_loop(); // Ejecutar el bucle del shell
    return 0;
}*/