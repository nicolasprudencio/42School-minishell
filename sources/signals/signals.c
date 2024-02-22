/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:33:02 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/22 03:47:58 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	sigint_handler(int sig);

void	sigint_handler(int sig)
{	
	(void)sig;
	get_status(130);
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
		get_status(130);
		rl_replace_line("", 0);
		put_str("\n", 1);
	}
}

// static void	st_handle_here(int sig, siginfo_t *info, void *context)
// {
// 	t_cmd_table *table;

// 	(void)context;
// 	table = (t_cmd_table *)info->si_value.sival_ptr;
// 	if (sig == SIGINT)
// 		get_status(130);
// 	put_cmdt(table);
// 	cmdt_destroy(&table);
// 	// put_cmdt(table);
// }

static void	st_handle_here(int sig)
{
	if (sig == SIGINT)
	{	
		put_endl("", 0);
		rl_on_new_line();
		exit(0);
		// printf("key : %i\n", g_key);
		// printf("amigo sto aqui\n");
	}
}

void	handle_heredoc_sig(int *fd)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	(void)fd;
	sa_sigint.sa_handler = &st_handle_here;
	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sigaction(SIGINT, &sa_sigint, NULL);
	put_endl("", 0);
	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	handle_exec_signals(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &st_handle_child;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
