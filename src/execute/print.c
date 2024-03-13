/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 05:01:14 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 05:16:13 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print(t_mini *mini)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;

	if (mini->flag_output != FALSE && mini->flag_append_output != FALSE)
		return (EXIT_FAILURE);
	fd = open(OUTFILE, O_RDONLY);
	if (fd == -1)
	{
		printf("Unable to open file.\n");
		return (1);
	}
	while ((bytes_read = read(fd, buffer, 1024)) > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
