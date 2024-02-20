/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:33:02 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/19 21:23:30 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	sigint_handler(int sig);

// void	assign_signals(void)
// {
// 	signal(SIGINT, sigint_handler);
// }

void	sigint_handler(int sig)
{
	(void)sig;
	put_str("\n", 0);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;
	
	sa_sigint.sa_handler = &sigint_handler;
	// sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_handler = SIG_IGN;
	// sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
	// signal(SIGINT, sigint_handler);
}

void	handle_exec_signals(int pid)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (pid == 0)
		sa.sa_handler = SIG_DFL;
	else
		sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);		
}

// void	handle_heredoc_signals(void)
// {
// 	struct sigaction sa;
// 	sa_sigint.sa_handler = ;
// 	sigemptyset(&sa_sigint.sa_mask);
// 	sigaction(SIGINT, &sa_sigint, NULL);
// }
