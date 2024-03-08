/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:06:23 by javgao            #+#    #+#             */
/*   Updated: 2024/03/08 22:57:13 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include "parser.h"
# include "init.h"
# include "builtins.h"
# include "pipex.h"
# include "hash.h"
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
# define SINGLE 1
# define PIPESS 0
//===builtins===
# define NUM_BUILTINS 8

typedef struct s_mini
{	
	char	*line;
	char	**arg_ori;
	t_hash	*hash_env;
	char	**paths;
	char	*infile; //ABSOLUTE DIRECTION
	char	**outfile; //ABSOLUTE DIRECTION
	char	**commands; // "ls -l | hola echo dfd" ----> *commands[0] = "ls -l" *command[1] = "|" *command[2] = "hola"
	char	***args; // "ls -l | hola echo dfd" ---> **args[0] = {""}; **args[1] = {"echo" "dfd"}; 
	int		is_echo_n; //Ver si hay que usar
	char	*is_builtin[NUM_BUILTINS + 1];
}	t_mini;

/*	--------------------------- INIT --------------------------- */
void	init_mini(t_mini *mini, char **envp);
void	init_builtin(t_mini *mini);
void	init_env(t_mini *mini, char **envp);
void	shell_loop(t_mini *mini);

/*	-------------------------- BUILTIN ---------------------------*/
int		is_builtin(char *command, t_mini *mini);
void	exec_builtin(char *command, char **arguments, t_mini *mini);
int		ft_echo(t_mini *mini, char **arguments, int flag);
int		ft_cd(t_mini *mini, char *argument);
int		ft_pwd(t_mini *mini);
int		ft_export(t_mini *mini, char *variable);
int		ft_unset(t_mini	*mini, char *variable);
int		ft_env(t_mini *mini);
int		ft_exit(t_mini *mini);

/*	-------------------------- EXECUTE ---------------------------*/
int		ft_execute(t_mini *mini);
int		single_command(t_mini *mini);
//void	not_builtin(char	*command, char	**commands, t_mini *mini, int flag);

/*	--------------------------- ERROR ----------------------------*/
int	print_error(char *error);

#endif
