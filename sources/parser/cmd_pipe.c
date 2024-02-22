/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_cmd_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:24:46 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:24:47 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	cmd_pipe(t_cmd_table **cmd_table)
{
	t_cmd_table	*last;
	t_command	*cmd_i;
	t_command	*cmd_o;
	int			pipefd[2];

	cmd_last(&last, cmd_table);
	if (pipe(pipefd))
		return (FALSE);
	cmd_i = last->command;
	cmd_o = last->prev->command;
	if (cmd_i->io[STDIN_FILENO] == STDIN_FILENO)
		cmd_i->io[STDIN_FILENO] = pipefd[STDIN_FILENO];
	else if (cmd_i->io[STDIN_FILENO] > 1)
		close(pipefd[STDIN_FILENO]);
	if (cmd_o->io[STDOUT_FILENO] == STDOUT_FILENO)
		cmd_o->io[STDOUT_FILENO] = pipefd[STDOUT_FILENO];
	else if (cmd_o->io[STDOUT_FILENO] > 1)
		close(pipefd[STDOUT_FILENO]);
	return (TRUE);
}
