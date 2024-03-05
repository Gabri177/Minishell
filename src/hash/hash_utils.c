/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:30:52 by yugao             #+#    #+#             */
/*   Updated: 2024/03/05 17:35:45 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hash.h"

t_bool	is_strsame(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (FALSE);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (FALSE);
		s1 ++;
		s2 ++;
	}
	return (*s1 == *s2);
}

int	hash_func(char *key)
{
	unsigned int	hash_val;
	int				i;

	hash_val = 0;
	i = 0;
	while (i < ft_strlen (key))
	{
		hash_val += key[i];
		i ++;
	}
	return (hash_val % HASH_SIZE);
}
