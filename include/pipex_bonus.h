/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:53:26 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/10 00:48:41 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

void	ft_exit_pipex(int n_exit);
int		ft_open(char *file, int n);
char	*ft_envp(char *variable, char **envp);
char	*ft_path(char *cmd, char **envp);
void	ft_exec(char *cmd, char **envp);
void	ft_free(char **arr);
int		pipex_bonus(int argc, char **argv, char **envp);

#endif
