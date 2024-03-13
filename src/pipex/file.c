/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 04:24:57 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 07:51:32 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	clean_outfile(t_mini *mini)
{
	int	fd;

	if (mini->flag_append_output != TRUE && mini->flag_output != TRUE)
		return (EXIT_SUCCESS);
	fd = open("./Libft/ft_printf/.outfile", O_WRONLY | O_TRUNC);
	if (fd == -1)
		return (print_error("Error opening the file on clean_outfile"));
	close (fd);
	return (EXIT_SUCCESS);
}