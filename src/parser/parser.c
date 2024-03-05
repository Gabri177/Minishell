/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:24 by yugao             #+#    #+#             */
/*   Updated: 2024/03/05 17:54:23 by javgao           ###   ########.fr       */
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

// int main (void)
// {
// 	char	test[]="pwd \"jaja\" cat>>file1>fie2<files4<<file5";
// 	char	**tem;

// 	tem = arg_abordar (test);
// 	if (!tem)
// 	 printf ("empty");
// 	arry_display (tem);
// 	printf ("index >>:%d\n", arry_get_index (tem, BIG_BIG));
// 	arry_del (&tem, arry_get_index (tem, BIG_BIG));
// 	arry_display (tem);
// 	arry_destory (tem);
// 	system ("leaks -q test");
// 	return 0;
// }