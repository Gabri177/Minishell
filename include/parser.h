/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:45 by yugao             #+#    #+#             */
/*   Updated: 2024/03/04 22:31:34 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "./minishell.h"

# define PIPE '|'   //|
# define BIG '>'    //>
# define LIT '<' //<
# define QUOTE_BIG '\"'
# define QUOTE_LIT '\''

# define PIPES "|"   //|
# define BIGS ">"    //>
# define LITS "<" //<
//=====arry_chr.c=====
int		chr_add(char **chrs, char c);
void	split_args(char ***args, char *ori);

//=====arry_strs.c=====
void	arry_destory(char **ary);
int		arry_add(char ***arys, char *val);
void	arry_display(char **ary);
void	arry_refresh(char ***arys, char **val);
#endif