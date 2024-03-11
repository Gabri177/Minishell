/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_argss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:34:09 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 23:28:59 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	h_args(int *has_args, int *i, char ***cur_args, char *cont)
{
	arry_add (cur_args, cont);
	*has_args = 1;
	(*i)++;
}

void	h_put_zero(char ****cmds, int *cmds_count
	, char ***current_args, int *i)
{
	*cmds = NULL;
	*cmds_count = 0;
	*current_args = NULL;
	*i = 0;
}

/* char	***reallocate_cmds(char ***cmds, int cmds_count)
{
	char	***new_cmds;
	int		i;

	i = 0;
	new_cmds = malloc(sizeof(char **) * (cmds_count + 1));
	if (new_cmds == NULL)
		return (NULL);
	while (i < cmds_count)
	{
		new_cmds[i] = arry_cpy_same (cmds[i]);
		i ++;
	}
	new_cmds[cmds_count] = NULL;
	return (new_cmds);
} */

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	new_ptr = NULL;
	// 如果申请的内存大小为 0,则释放原有内存并返回 NULL
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	// 如果原有指针为 NULL,等同于 malloc
	if (ptr == NULL)
		return (malloc(new_size));
	// 申请新的内存块
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL); // 内存分配失败
	// 计算需要复制的字节数,避免越界
	size_t bytes_to_copy = new_size < sizeof(ptr) ? new_size : sizeof(ptr);
	// 复制原有数据到新内存块
	ft_memcpy(new_ptr, ptr, bytes_to_copy);
	// 释放原有内存块
	free(ptr);
	return (new_ptr);
}

void	h_fill_zero(char ***cmd, char ***current_args)
{
	*cmd = NULL;
	*current_args = NULL;
}

char	***args_to_args(char **args)
{
	char	***cmds;
	int		cmds_count;
	char	**current_args;
	int		i;
	int		has_args;

	if (!args || !*args || !**args)
		return (NULL);
	h_put_zero (&cmds, &cmds_count, &current_args, &i);
	while (args[i] != NULL)
	{
		i++;
		has_args = 0;
		while (args[i] != NULL && !is_strsame(args[i], "|"))
			h_args (&has_args, &i, &current_args, args[i]);
		if (!has_args)
			arry_add(&current_args, "哈");
		cmds_count ++;
		cmds = ft_realloc(cmds, sizeof (char**) * (cmds_count + 1));
		//cmds = reallocate_cmds (cmds, cmds_count);
		cmds[cmds_count - 1] = current_args;
		h_fill_zero (&cmds[cmds_count], &current_args);
		/* cmds[cmds_count] = NULL;
		current_args = NULL; */
		if (args[i] != NULL)
			i ++;
	}
	return (cmds);
}
