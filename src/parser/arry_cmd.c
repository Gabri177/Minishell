/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:09:45 by javgao            #+#    #+#             */
/*   Updated: 2024/03/06 05:14:19 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//将comand 和后面的flag 合并在一起 并将修改作用到原来的数组中 无泄漏
static void	args_merge_cmds(char ***args, int keep_ori)
{
	int		i;
	char	*tem;
	char	*tem_join;

	i = 0;
	if (!*args || !**args)
		return ;
	while ((*args)[i])
	{
		if ((*args)[i][0] == '-' && (*args)[i - 1])
		{
			tem = (*args)[i - 1];
			tem_join = ft_strjoin (" ", (*args)[i]);
			(*args)[i - 1] = ft_strjoin (tem, tem_join);
			free (tem);
			free (tem_join);
			if (keep_ori == TRUE)
				arry_del (args, i);
			i --;
		}
		i ++;
	}
}

//这里传入的args必须是已经删除了输入重定向和输出重定向的二维数组, 输出一个单纯的有命令和flag还有管道符组成的数组
char	**args_to_cmds(char ***args)
{
	char	**new;
	int		i;

	new = NULL;
	i = 1;
	if (!*args || !**args)
		return (NULL);
	args_merge_cmds (args, TRUE);
	arry_add (&new, (*args)[0]);
	while ((*args)[i])
	{
		if (is_strsame ((*args)[i], "|") && (*args)[i + 1])
		{
			arry_add (&new, "|");
			arry_add (&new, (*args)[i + 1]);
		}
		i ++;
	}
	return (new);
}

//计算ori_arg中要分割成几个二维数组
int	count_args(char **args)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!args || !*args)
		return (n);
	if (!is_strsame (args[0], PIPES))
	{
		n ++;
		i ++;
	}
	while (args[i])
	{
		if (is_strsame (args[i], PIPES))
			n ++;
		i ++;
	}
	printf ("二维数组数量: %d\n", n);
	return (n);
}

//传入合并命令后的ori数组 一般在用完args_to_cmd后使用, 我们会得到去掉simple command后的ori_args数组
void	args_no_cmds(char ***args)
{
	int	i;

	i = 1;
	if (!*args || !**args)
		return ;
	if (!is_strsame ((*args)[0], PIPES))
		arry_del (args, 0);
	while ((*args)[i])
	{
		if (is_strsame ((*args)[i], PIPES) && (*args)[i + 1]
			&& !is_strsame ((*args)[i + 1], PIPES))
			arry_del (args, i + 1);
		i ++;
	}
	arry_display (*args);
}

//根据没有基础命令的数组进行参数的获取, 生成二维数组, 每获取一个数据就会删除一个数据
char	**get_args(char ***args)
{
	char	**new;

	new = NULL;
	if (!*args || !**args)
		return (arry_add(&new, "NULL"), new);
	if ((*args)[0] && is_strsame ((*args[0]), PIPES))
	{
		arry_del (args, 0);
		arry_add(&new, "NULL");
		return (new);
	}
	while ((*args)[0] && !is_strsame ((*args[0]), PIPES))
	{
		arry_add (&new, (*args)[0]);
		arry_del (args, 0);
		if (is_strsame ((*args[0]), PIPES))
		{
			arry_del (args, 0);
			break ;
		}
	}
	return (new);
	// if ((*args)[0] && is_strsame ((*args)[0], PIPES))
	// {
	// 	arry_add (&new, "NULL");
	// 	arry_del (args, 0);
	// 	return (new);
	// }
	
}

//销毁三维数组
void	argss_destory(char ***argss)
{
	int	i;

	i = 0;
	while (argss[i])
	{
		arry_destory (argss[i]);
		i ++;
	}
	free (argss);
}

//这个函数是用来将没有基础命令且包含管道符号的数组进行处理, 并根据index返回一个三维数组, 每个数组都是对应命令的参数
char	***args_to_args(char ***args)
{
	char	***new;
	int		i;
	int		len;

	new = NULL;
	i = 0;
	args_no_cmds (args);
	len = count_args (*args);
	if (!args || !*args || len == 0)
		return (new);
	new = malloc (sizeof (char **) * (len + 1));
	while (i <= len)
		new[i++] = NULL;
	i = 0;
	while (i < len)
	{
		new[i] = get_args (args);
		i ++;
	}
	i = 0;
	while (i < len)
	{
		printf ("argumentos de index[%d]:\n", i);
		arry_display (new[i]);
		i ++;
	}
	return (new);
}