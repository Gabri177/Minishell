/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:24 by yugao             #+#    #+#             */
/*   Updated: 2024/03/04 22:26:21 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

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
	char	test[]="pwd \"\"jaja\"\"";
	static char	**tem;
	static char	**prueba;

	// tem = arg_abordar (test);
	// if (!tem)
	// 	return 1;
	// int i = 0;
	// while (tem[i])
	// {
	// 	printf ("==%s=", tem[i]);
	// 	i ++;
	// }

	/* prueba = NULL;
	split_args (&prueba, test);
	arry_display (prueba);
	arry_destory (prueba); */
	tem = arg_abordar (test);
	if (!tem)
	 printf ("empty");
	arry_display (tem);
	arry_destory (tem);
	system ("leaks -q test");
	return 0;
}