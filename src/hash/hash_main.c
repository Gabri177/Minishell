/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:29:20 by yugao             #+#    #+#             */
/*   Updated: 2024/03/03 02:07:37 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hash.h"

int	main(void)
{
	t_hash	*hash;

	hash = hash_init ();
	hash_push (hash, "test1", "jajajaja");
	hash_push (hash, "cd", "cd1111111");
	hash_push (hash, "cd", "cd22222222");// si añadimos con el mismo key, vamos a eliminar el key antiguo y reescribirlo
	hash_push (hash, "cat", "cat direction");
	hash_push (hash, "echo", "echo direction");
	printf (">===hash_grep : %s ===\n\n", hash_grep (hash, "tes"));
	printf (">===hash_grep : %s ===\n\n", hash_grep (hash, "cd"));
	printf (">===hash_grep : %s ===\n\n", hash_grep (hash, "echo"));
	printf (">===hash_grep : %s ===\n\n", hash_grep (hash, "cat"));
	hash_display (*hash);
	printf ("=========\n");
	hash_del (hash, "cd");
	hash_del (hash, "cd");
	hash_display (*hash);
	hash_destory (hash);
	system ("leaks -q test");
	return (0);
}