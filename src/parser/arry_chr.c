#include "../../include/parser.h"

//这是一个创建字符串的文件, 初始化以后, 可以不断添加单个字符, 长度自动扩张.
int	chr_add(char **chrs, char c)
{
	char	*tem;

	if (!*chrs)
	{
		*chrs = malloc (sizeof (char) * 2);
		if (!*chrs)
			return (FALSE);
		(*chrs)[0] = c;
		(*chrs)[1] = '\0';
		return (TRUE);
	}
	tem = malloc (sizeof (char) * (strlen (*chrs) + 2));
	if (!tem)
		return (FALSE);
	strcpy (tem, *chrs);
	tem[strlen (*chrs)] = c;
	tem[strlen (*chrs) + 1] = '\0';
	free (*chrs);
	*chrs = tem;
	return (TRUE);
}

//处理大于号 小于号和 管道符号情况
void	is_chr_special(char **c, char ***new_args, char **new_arg)
{
	if (**c == LINE || **c == BIG || **c == LIT)
	{
		arry_refresh (new_args, new_arg);
		if (**c == LINE)
			arry_add (new_args, LINES);
		if (**c == BIG)
			arry_add (new_args, BIGS);
		if (**c == LIT)
			arry_add (new_args, LITS);
		(*c) += 1;
	}
}

void	is_chr_quote(char **c, char ***new_args, char **new_arg)
{
	char	mark;

	if (**c == QUOTE_LIT)
		mark = QUOTE_LIT;
	if (**c == QUOTE_BIG)
		mark = QUOTE_BIG;
	if (**c == mark)
	{
		arry_refresh (new_args, new_arg);
			chr_add (new_arg, **c);//这里我加上了引号
		(*c) += 1;
		while (**c != mark && **c)
		{
			chr_add (new_arg, **c);
			(*c) += 1;
		}
			chr_add (new_arg, **c);//这里我加上了引号
		arry_refresh (new_args, new_arg);
		(*c) += 1;
	}
}

//控制tem指针的位置将空格跳过去
static void	skip_space(char **tem)
{
	while (**tem && **tem != ' ')
		(*tem) += 1;
}

//将一个字符串进行分割， 碰到< > | " ' 和几个符号进行分割， 目前的问题是当有两个引号同时围住一个元素的时候
//会按照最近的阔考进行配对
//在这个函数中 ori这个参数是函数使用者负责 如果是申请的变量要用户去释放， 函数内不对ori这个参数进行释放
void	split_args(char ***args, char *ori)
{
	char	*tem;
	char	*new_arg;
	char	**new_args;

	if (!ori || !*ori)
		*args = NULL;//error
	new_arg = NULL;
	new_args = NULL;
	tem = ft_strtrim (ori, " ");
	ori = tem;
	while (*tem)
	{
		if (*tem == ' ' && new_arg)
		{
			arry_refresh (&new_args, &new_arg);
			skip_space (&tem);
		}
		is_chr_special (&tem, &new_args, &new_arg);
		is_chr_quote (&tem, &new_args, &new_arg);
		if (*tem != ' ' && *tem != '|' && *tem != '>' && *tem != '<' && *tem != QUOTE_BIG && *tem != QUOTE_LIT)
			chr_add (&new_arg, *tem);
		tem ++;
	}
	arry_refresh (&new_args, &new_arg);
	free (ori);
	*args = new_args;
}
