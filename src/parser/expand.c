/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:05:27 by javgao            #+#    #+#             */
/*   Updated: 2024/03/10 20:22:53 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//nos retorna una cadena que es el nombre de la variabe que al terminar usarla
//hay que liberar
char	*get_var_name(const char *str)
{
	char	*new;

	new = NULL;
	/* if (!is_var_exist(str))
		return (new); */
	while (*str && *str != '$')
		str ++;
	str ++;
	while (*str && *str != ' ' && *str != '\'' && *str != '\"')
	{
		chr_add (&new, *str);
		str ++;
	}
	return (new);
}

//nos retorno una cadena no libarable
char	*get_hash_val(t_hash *hash, const char *key)
{
	if (!hash_grep (hash, (char *)key))
		return (hash_grep (hash, (char *)key));
	return (NULL);
}

//下面代码是下面函数的替代部分
/* void trash(void)
{
	if (*str == '$')
		{
			args_add_var (&str, hash, &new);
			var_name = get_var_name (str);
			var_value = hash_grep (hash, var_name);
			if (var_value)
			{
				while (*var_value != '=')
					var_value ++;
				var_value ++;
				while (*var_value)
				{
					chr_add (&new, *var_value);
					var_value ++;
				}
			}
			str += (ft_strlen (var_name));
			if (!var_name)
				free (var_name);
			var_value = NULL;
		}
} */
void	args_add_var(char **str, t_hash *hash, char **new)
{
	char	*var_name;
	char	*var_value;

	var_name = get_var_name (*str);
	var_value = hash_grep (hash, var_name);
	if (var_value)
	{
		while (*var_value != '=')
			var_value++;
		var_value++;
		while (*var_value)
		{
			//printf ("%c ", *var_value);
			chr_add (new, *var_value);
			var_value ++;
		}
	}
	(*str) += ft_strlen (var_name);
	if (var_name)
		free (var_name);
	var_value = NULL;
}

//liberable
char	*split_arg_filter(char *str, t_hash *hash)
{
	char	*new;

	new = NULL;
	while (*str)
	{
		if (*str && *str == '\'')
		{
			str ++;
			while (*str != '\'')
				chr_add (&new, *str ++);
			str ++;
		}
		else if (*str && *str == '\"')
		{
			str ++;
			while (*str != '\"')
			{
				if (*str == '$')
					args_add_var (&str, hash, &new);
				else
					chr_add (&new, *str);
				str ++;
			}
			str ++;
		}
		else
		{
			if (*str == '$')
				args_add_var (&str, hash, &new);
			else
				chr_add (&new, *str);
			str ++;
			//chr_add (&new, *str ++);
		}
	}
	return (new);
}

char	**split_filter(char **args, t_hash *hash)
{
	char	**new;
	int		i;
	char	*filt;

	i = 0;
	new = NULL;
	if (!args || !*args)
	return (NULL);
	while (args[i])
	{
		if (!is_strsame ("\"\"", args[i]) && !is_strsame ("\'\'", args[i]))
		{
			filt = split_arg_filter (args[i], hash);
			//printf ("new:!%s!", filt);
			arry_add (&new, filt);
			free (filt);
			filt = NULL;
		}
		else
			arry_add (&new, "\b");
		i ++;
	}
	arry_destory (args);
	return (new);
}

/* int	main(void)
{
	char	ctest[] = "thisis\'$atest\' ";
	char	*name;

	name = get_var_name (ctest);
	printf ("var_name:%s\n", name);
	return 0;
} */
