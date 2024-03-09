/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:14:06 by javgao            #+#    #+#             */
/*   Updated: 2024/03/09 06:04:55 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	event(void)
{
	return (EXIT_SUCCESS);
}

static void	sig_hand(int sig)
{
	(void)sig;
	printf ("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_sig(void)
{
	rl_event_hook = event;
	signal (SIGINT, sig_hand);
	signal (SIGQUIT, SIG_IGN);
}
