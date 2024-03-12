/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:37:32 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 12:05:28 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <errno.h>

#define INFILE "./Libft/ft_printf/.infile"
#define OUTFILE "./Libft/ft_printf/.outfile"

typedef struct s_cmd
{
	bool	found;
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		size;
	int		infile;
	int		outfile;
	t_cmd	*cmds;
	int		**pipes;
	char	**paths;
	char	**argv;
	char	**envp;
	int		*child_pids;
	bool	heredoc;
	int		exitcode;
}	t_pipex;

/*	--------------------------- CHILD --------------------------- */
void	redirect(t_pipex pipex, int input, int output);
void	children(t_pipex pipex, int i);
void	child(t_pipex pipex, int i, int input, int output);

/*	--------------------------- ERROR --------------------------- */
void	error_message(char *file);
void	cmd_not_found(t_pipex *pipex, int i);

/*	--------------------------- FREE --------------------------- */
bool	close_all_fds(t_pipex *pipex);
bool	free_pipex(t_pipex *pipex);

/*	------------------------- HERE_DOC -------------------------- */
void	open_here_doc(t_pipex *pipex);
void	here_doc(t_pipex *pipex);

/*	--------------------------- MAIN --------------------------- */
int		pipex_bonus(int argc, char **argv, char **envp);
bool	pipex_init(t_pipex *pipex, int argc, char **argv, char **envp);
bool	init_cmds(t_pipex *pipex);

/*	--------------------------- PARSE --------------------------- */
bool	is_command(t_pipex *pipex, char *command, int i);
void	find_command(t_pipex *pipex, int i);
void	find_paths(t_pipex *pipex);
void	open_files(t_pipex *pipex);
bool	parse_input(t_pipex *pipex);

/*	--------------------------- PIPEX --------------------------- */
bool	create_pipes(t_pipex *pipex);
bool	wait_pids(t_pipex *pipex);
bool	allocate_pids(t_pipex *pipex);
bool	execute(t_pipex *pipex);

#endif
