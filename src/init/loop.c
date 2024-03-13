/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:45:16 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 09:46:20 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*static void	check_file(t_mini *mini)
{
	int		fd;
	char	*str;

	fd = open(INFILE, O_RDONLY, O_TRUNC);
	str = get_next_line(fd);
	if (str)
		clean_outfile(mini);
	close (fd);
}*/

void	shell_loop(t_mini *mini)
{
	char	*line;

	while (1)
	{
		clean_outfile(mini);
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
			g_sig_refresh (mini->hash_env, g_sig);
			mini->arg_ori = arg_abordar (line);
			if (!mini->arg_ori)
				continue ;
			free(line);
			mini->arg_ori = split_filter (mini->arg_ori, mini->hash_env);
			line = NULL;
			mini->outfile = args_to_outfile (&mini->arg_ori);
			mini->infile = filter_args_infile (args_to_infile (&mini->arg_ori));
			update_statu_write_outfile (mini, mini->outfile);
			update_statu_write_dogii(mini, mini->infile);
			mini->cmds_and_args = args_to_cmds_args (mini->arg_ori);
			mini->commands = args_to_cmds (&mini->arg_ori);
			mini->args = args_to_args (mini->arg_ori);
		}
		open_all_files(mini);
		ft_execute(mini);
		print (mini);
		init_re (mini);
	}
}
