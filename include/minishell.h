/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:06:23 by javgao            #+#    #+#             */
/*   Updated: 2024/03/04 16:38:46 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include "parser.h"
# include "init.h"
# include "builtins.h"
# include "pipex.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <string.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TRUE 1
# define FALSE 0
# define NUM_BUILTINS 7

typedef struct s_mini
{	
	int		argc; //Este creo que nos sobra porque va a contar mal
	char	**argv;
	char	**envp;
	char	*pwd;
	char	*old_pwd;
	char	**paths;
	char	*infile; //ABSOLUTE DIRECTION
	char	**outfile; //ABSOLUTE DIRECTION
	char	**commands; // ls -l | wc -l ----> commands[0] = "ls -l" command[1] = "|" command[2] = "wc -l"
	char	***args;
	int		is_echo_n; //
	char	*is_builtin[NUM_BUILTINS + 1];
}	t_mini;

/*	--------------------------- INIT --------------------------- */
void	init_mini(t_mini *mini, int argc, char **argv, char **envp);
void	init_builtin(t_mini *mini);

/*	-------------------------- BUILTIN ---------------------------*/
int		is_builtin(char *command, t_mini *mini);
void	exec_builtin(char *command, t_mini *mini);
int		ft_echo(t_mini *mini);

#endif