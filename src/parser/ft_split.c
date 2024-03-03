/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:09:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/03 19:09:58 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static char	*str_cpy(const char *allstr, int initp, int endp);
static int	is_sep(char *strsep, char c);
static char	**ele_count(char *str, char *sep);

char	**ft_split(char *str, char *charset)
{
	char	**fin;
	int		head;
	int		index;
	int		tamano;

	index = 0;
	tamano = 0;
	fin = ele_count (str, charset);
	while (str [index])
	{
		if (!is_sep(charset, str[index]))
		{
			head = index;
			while (!is_sep(charset, str[index]) && str[index])
				index ++;
			fin[tamano] = str_cpy (str, head, index);
			tamano ++;
		}
		else
			index ++;
	}
	return (fin);
}

static char	*str_cpy(const char *allstr, int initp, int endp)
{
	char	*fin;
	int		index;

	index = 0;
	fin = (char *) malloc (sizeof (char) * (endp - initp + 1));
	while (initp + index < endp)
	{
		fin[index] = allstr[initp + index];
		index ++;
	}
	fin[index] = '\0';
	return (fin);
}

static int	is_sep(char *strsep, char c)
{
	int	index;

	index = 0;
	while (c != '\0' && strsep[index])
	{
		if (c == strsep[index])
			return (TRUE);
		index ++;
	}
	return (FALSE);
}

char	**ele_count(char *str, char *sep)
{
	int		count;
	int		index;
	char	**final;

	count = 0;
	index = 0;
	if (!str || !*str)
	{
		final = (char **)malloc(sizeof(char *));
		final[0] = NULL;
		return (final);
	}
	while (str[index])
	{
		if (!is_sep(sep, str[index]))
			if (index == 0 || is_sep(sep, str[index - 1]))
				count++;
		index ++;
	}
	final = (char **)malloc(sizeof(char *) * (count + 1));
	final[count] = NULL;
	return (final);
}

/*
int main ()
{
	char	test[100] = "test1-test2+test3#";
	char	esp[100] = "t";
	char	**fin;
	int		index;

	fin = ft_split (test, esp);
	index =0;
	while (fin[index])
	{
		printf ("%s \n", fin[index]);
		index ++;
	}
}
*/
