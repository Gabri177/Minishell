/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 05:01:14 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 09:15:52 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print(t_mini *mini)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;

	if (mini->flag_output == TRUE || mini->flag_append_output == TRUE)
		return (EXIT_FAILURE);
	(void)mini;
	fd = open(OUTFILE, O_RDONLY);
	while ((bytes_read = read(fd, buffer, 1024)) > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
