/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:36:07 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/07 16:37:13 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_child_process(t_cmd_table *cmd_table, 
		t_pushdown_automaton * parse_bot);

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot)
{
	pid_t	pid;
	t_cmd_table	*aux;
	int	status;

	aux = *cmd_table;
	while (aux)
	{
		pid = fork();
		if (pid < 0)
			return (FALSE);
		if (pid == 0)
		{
			if (!st_child_process(aux, parse_bot))
				return (FALSE);
		}
		else
		{
			waitpid(pid, &status, 0);
			aux = aux->next;
		}
	}
	return (TRUE);
}

static int	st_child_process(t_cmd_table *cmd_table, 
		t_pushdown_automaton *parse_bot)
{
	int	io[2];
	char	**command;

	command = cmd_table->command->parsed;
	io[STDIN_FILENO] = cmd_table->command->io[STDIN_FILENO];
	io[STDOUT_FILENO] = cmd_table->command->io[STDOUT_FILENO];
	if (io[STDIN_FILENO] != STDIN_FILENO)
		dup2(STDIN_FILENO, io[STDIN_FILENO]);
	if (io[STDOUT_FILENO] != STDOUT_FILENO)
		dup2(STDOUT_FILENO, io[STDOUT_FILENO]);
	if (is_terminal2(parse_bot->env_list, &command[0]))
	{
		execve(command[0], command, NULL);
	}
	automaton_destroy(parse_bot);
	automaton_cmdt_destroy(&cmd_table);
	exit(0);
}
