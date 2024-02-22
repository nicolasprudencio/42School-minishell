/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:28:32 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/22 09:28:34 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_sighandler(int signal);

void	handle_heredoc_signals(void)
{
	struct sigaction	sa_sig;

	sa_sig.sa_flags = 0;
	sa_sig.sa_handler = &st_sighandler;
	sigemptyset(&sa_sig.sa_mask);
	sigaction(SIGINT, &sa_sig, NULL);
	sigaction(SIGQUIT, &sa_sig, NULL);
}

static void	st_sighandler(int signal)
{
	if (signal == SIGINT)
	{
		put_endl("", 1);
		if (get_pipe(-1) != -1)
			close(get_pipe(-1));
		exit(get_status(-1));
	}
}
