/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:33:02 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/20 13:21:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	sigint_handler(int sig);

void	sigint_handler(int sig)
{	
	(void)sig;
	put_str("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;
	
	sa_sigint.sa_handler = &sigint_handler;
	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

static void	st_handle_child(int sig)
{
	if (sig == SIGQUIT)	
	{
		put_str("Quit (core dumped)\n", STDOUT_FILENO);
		rl_replace_line("", 0);
	}
	else if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		put_str("\n", 1);
	}

}

void	handle_exec_signals()
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &st_handle_child;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
