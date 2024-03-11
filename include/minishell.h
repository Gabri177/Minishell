/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:06:23 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 03:23:43 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include "parser.h"
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
# include <signal.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TRUE 1
# define FALSE 0
# define SINGLE 1
# define PIPESS 0
# define REDIRECT 1
# define APPEND 2
//===builtins===
# define NUM_BUILTINS 7
# define PROMPT "\x1b[1;32mminishell\x1b[0m\x1b[1;36m > \x1b[0m"

# define WELCOM1 "\033[1;32m ███▄ ▄███▓██▓███▄    █ ██▓ ██████ ██░ ██▓█████ ██▓    ██▓    \n"
# define WELCOM2 "\033[0;32m▓██▒▀█▀ ██▓██▒██ ▀█   █▓██▒██    ▒▓██░ ██▓█   ▀▓██▒   ▓██▒    \n"
# define WELCOM3 "\033[1;34m▓██    ▓██▒██▓██  ▀█ ██▒██░ ▓██▄  ▒██▀▀██▒███  ▒██░   ▒██░    \n"
# define WELCOM4 "\033[0;34m▒██    ▒██░██▓██▒  ▐▌██░██░ ▒   ██░▓█ ░██▒▓█  ▄▒██░   ▒██░    \n"
# define WELCOM5 "\033[1;35m▒██▒   ░██░██▒██░   ▓██░██▒██████▒░▓█▒░██░▒████░██████░██████▒\n"
# define WELCOM6 "\033[0;35m░ ▒░   ░  ░▓ ░ ▒░   ▒ ▒░▓ ▒ ▒▓▒ ▒ ░▒ ░░▒░░░ ▒░ ░ ▒░▓  ░ ▒░▓  ░\n"
# define WELCOM7 "\033[0;35m░  ░      ░▒ ░ ░░   ░ ▒░▒ ░ ░▒  ░ ░▒ ░▒░ ░░ ░  ░ ░ ▒  ░ ░ ▒  ░\n"
# define WELCOM8 "\033[1;35m░      ░   ▒ ░  ░   ░ ░ ▒ ░  ░  ░  ░  ░░ ░  ░    ░ ░    ░ ░   \n"
# define WELCOM9 "\033[0;35m       ░   ░          ░ ░       ░  ░  ░  ░  ░  ░   ░  ░   ░  ░\n"


typedef int	t_bool;
typedef struct s_mini
{
	char	*line;
	char	**arg_ori;
	t_hash	*hash_env;
	char	**paths;
	char	*infile; //ABSOLUTE DIRECTION
	char	**outfile; //ABSOLUTE DIRECTION
	char	**commands; // "ls -l | hola echo dfd" ----> "ls -l" "|" "hola"
	char	***args; // "ls -l | hola echo dfd" ---> {""} {"echo" "dfd"}; 
	int		is_echo_n; //Ver si hay que usar
	char	*is_builtin[NUM_BUILTINS + 1];
	int		flag_infile;
	int		flag_outfile;
}			t_mini;

/*	--------------------------- INIT --------------------------- */
void	init_mini(t_mini *mini, char **envp);
void	init_builtin(t_mini *mini);
void	init_env(t_mini *mini, char **envp);
void	shell_loop(t_mini *mini);
void	welcom(void);
/*	-------------------------- BUILTIN ---------------------------*/
int		is_builtin(char *command, t_mini *mini);
void	exec_builtin(char *command, char **arguments, t_mini *mini);
int		ft_echo(t_mini *mini, char **arguments, int flag);
int		ft_cd(t_mini *mini, char *argument);
int		ft_pwd(t_mini *mini);
int		ft_export(t_mini *mini, char *variable);
int		ft_unset(t_mini	*mini, char *variable);
int		ft_env(t_mini *mini);
int		ft_exit(char *line);

/*	-------------------------- EXECUTE ---------------------------*/
int		ft_execute(t_mini *mini);
int		single_command(t_mini *mini);
void	not_builtin(char	*command, char	**commands, t_mini *mini, int flag);
void		ft_exec_single(char *cmd, char **envp);

/*	--------------------------- ERROR ----------------------------*/
int		print_error(char *error);

/*	--------------------------- SIGNAL ---------------------------*/
void	init_sig(void);

/*	---------------------------- FREE ----------------------------*/
void	ft_free_four(char **one, char **two, char **three, char **four);

/*	---------------------------- UTILS ----------------------------*/
char	*ft_lower(char *str);

/*	---------------------------- EXPAND ----------------------------*/
char	**split_filter(char **args, t_hash *hash);

/*	---------------------------- PIPEX -----------------------------*/
void	ft_exit_pipex(int n_exit);
int		ft_open(char *file, int n);
char	*ft_envp(char *variable, char **envp);
char	*ft_path(char *cmd, char **envp);
void	ft_exec(char *cmd, char **envp);
void	ft_free(char **arr);
void	pipex_bonus(t_mini *mini, int argc, char **argv, char **envp);

#endif
