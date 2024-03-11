/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:24 by yugao             #+#    #+#             */
/*   Updated: 2024/03/11 04:08:23 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quote_check(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str ++;
			while (*str && *str != '\'')
				str ++;
			if (!*str)
				return (-1);
		}
		else if (*str == '\"')
		{
			str ++;
			while (*str && *str != '\"')
				str ++;
			if (!*str)
				return (-1);
		}
		str ++;
	}
	return (1);
}

char	**arg_abordar(char *ori)
{
	char	**new_arvs;

	if (!ori)
		return (NULL);
	if (!ori[0])
		return (NULL);
	if (quote_check (ori) == -1)
		return (print_error("Those quotes are not pared!"), NULL);
	new_arvs = NULL;
	split_args (&new_arvs, ori);
	return (new_arvs);
}
/*
int main (void)
{
	// situacion como ||||||| o >>>>>> o <<<<<<<< o <> ><   >>>>le3 中间的">>"被当成文件了 所以le3没有被删除
	char	test[]=" ls >file1 >>file2 -la arg1[1] arg2[1]|grep >file >>fill| cat -d arg1[3] | cd | ls arg1[4] arg2[4]";//write a checker to theck the ilegal situation
	char	**ori_args;
	char	**outfile;
	char	**cmds;
	char	***argss;
	//char	**no_cmds;

	ori_args = arg_abordar (test);
	if (!ori_args)
		printf ("empty");
	//=======================================
	printf ("original args:\n");
	arry_display (ori_args);
	//=======================================
	outfile = args_to_outfile (&ori_args);
	printf ("outfile:\n");
	arry_display (outfile);
	//=======================================
	printf ("args sin outfiles:\n");
	arry_display (ori_args);
	//=======================================
	printf ("simple commands:\n");
	cmds = args_to_cmds (&ori_args);
	arry_display (cmds);
	arry_display (ori_args);
	//=======================================
	printf ("argumentossss:\n");
	argss = args_to_args (&ori_args);
	


	argss_destory (argss);
	arry_destory (cmds);
	arry_destory (ori_args);
	arry_destory (outfile);
	system ("leaks -q minishell");
	return 0;
}*/