/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:24 by yugao             #+#    #+#             */
/*   Updated: 2024/03/05 23:04:43 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quote_check(char *str)
{
	int	little;
	int	big;
	int	i;

	little = 0;
	big = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 34)
			little ++;
		if (str[i] == 39)
			big ++;
	}
	if (little > 0 && little % 2 != 0)
		return (FALSE);
	if (big > 0 && big % 2 != 0)
		return (FALSE);
	return (TRUE);
}

char	**arg_abordar(char *ori)
{
	char	**new_arvs;

	if (!ori)
		return (NULL);//error
	if (!ori[0])
		return (NULL);//null context
	if (!quote_check (ori))
		return (NULL);//error
	new_arvs = NULL;
	split_args (&new_arvs, ori);
	return (new_arvs);
}

int main (void)
{
	// situacion como ||||||| o >>>>>> o <<<<<<<< o <> ><   >>>>le3 中间的">>"被当成文件了 所以le3没有被删除
	char	test[]="echo >file1 -ls >> file2 | gr\"quote\"ep < c|at >fi>> le3>>file4";//write a checker to theck the ilegal situation
	char	**ori_args;
	char	**outfile;

	ori_args = arg_abordar (test);
	if (!ori_args)
		printf ("empty");
	arry_display (ori_args);
	outfile = args_to_outfile (&ori_args);
	arry_display (outfile);
	arry_display (ori_args);
	arry_destory (ori_args);
	arry_destory (outfile);
	system ("leaks -q test");
	return 0;
}