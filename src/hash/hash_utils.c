/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:30:52 by yugao             #+#    #+#             */
/*   Updated: 2024/03/12 21:45:14 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <unistd.h>

int	hash_func(char *key)
{
	unsigned int	hash_val;
	size_t			i;

	hash_val = 0;
	i = 0;
	while (i < ft_strlen (key))
	{
		hash_val += key[i];
		i ++;
	}
	return (hash_val % HASH_SIZE);
}

void	hash_display(t_hash	h)
{
	int	i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (h.bucket[i])
			list_print (h.bucket[i]);
		i ++;
	}
}

void	list_print(t_node *l)
{
	t_node	*tem;
	int		num;

	num = 0;
	if (!l || !l->next)
		return ;
	tem = l->next;
	while (tem)
	{
		if (!is_strsame (tem->key, "?"))
			printf ("%s\n", tem->val);
		num ++;
		tem = tem->next;
	}
}

char	**hash_to_arry(t_hash	*h)
{
	int		i;
	t_node	*cur;
	char	**new;

	i = 0;
	new = NULL;
	while (i < HASH_SIZE)
	{
		if (h->bucket[i])
		{
			cur = h->bucket[i]->next;
			while (cur)
			{
				arry_add (&new, cur->val);
				cur = cur->next;
			}
		}
		i ++;
	}
	return (new);
}
