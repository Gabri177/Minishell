/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:45:16 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 08:34:53 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_loop(t_mini *mini)
{
	char	*line;

	while (1)
	{
		init_sig ();
    	line = readline(PROMPT);
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
			g_sig_refresh (mini->hash_env, g_sig); // the etatus of those build functions has not take
			mini->arg_ori = arg_abordar (line);
			if (!mini->arg_ori)
				continue ;
			free(line);
			//arry_display (mini->arg_ori);							//Imprime el parser
			mini->arg_ori = split_filter (mini->arg_ori, mini->hash_env);
			line = NULL;
			//printf ("original :\n");							//Imprime el parser
			//arry_display (mini->arg_ori);							//Imprime el parser
			mini->outfile = args_to_outfile (&mini->arg_ori);
			//printf ("outfile :\n");							//Imprime el parser
			//arry_display (mini->outfile);							//Imprime el parser
			mini->infile = filter_args_infile (args_to_infile (&mini->arg_ori));
			//printf ("infile :\n");							//Imprime el parser
			update_statu_write_outfile (mini, mini->outfile);
			update_statu_write_dogii(mini, mini->infile);
			//arry_display (mini->infile);							//Imprime el parser
			mini->cmds_and_args = args_to_cmds_args (mini->arg_ori);
			//printf ("cmds_and_args :\n");							//Imprime el parser
			//arry_display (mini->cmds_and_args);							//Imprime el parser
			mini->commands = args_to_cmds (&mini->arg_ori);
			//printf ("command :\n");							//Imprime el parser
			//arry_display (mini->commands);							//Imprime el parser
			//arry_display (mini->arg_ori);							//Imprime el parser
			mini->args = args_to_args (mini->arg_ori);
			//printf ("ARGSSSSSSS :\n");							//Imprime el parser
			//argss_display (mini->args);							//Imprime el parser
		}
		// Aquí se pueden añadir códigos para procesar el comando
		open_all_files(mini);
		ft_execute(mini);
		print(mini);
		init_re (mini);
	}
}

/*int main() {
    // Inicialización de la biblioteca readline
    rl_on_new_line();
    shell_loop(); // Ejecutar el bucle del shell
    return 0;
}*/