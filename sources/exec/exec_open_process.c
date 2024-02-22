/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:56:26 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/22 04:39:42 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_child_process(t_cmd_table *cmd_table,
				t_pushdown_automaton *parse_bot);
static void	st_close_all_fds(t_cmd_table *cmd);
static void	st_dup(t_cmd_table *cmd);

int	exec_open_process(t_cmd_table **cmd, t_pushdown_automaton *parse_bot)
{
	int			status;
	pid_t		pid;

	handle_exec_signals();
	pid = fork();
	status = 0;
	if (pid < 0)
		return (FALSE);
	if (pid == 0)
		st_child_process(*cmd, parse_bot);
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

static void	st_close_all_fds(t_cmd_table *cmd)
{
	t_cmd_table	*aux;

	aux = cmd;
	while (aux->next)
	{
		if (aux->command->io[STDIN_FILENO] != STDIN_FILENO
			&& aux->command->io[STDIN_FILENO] != -1)
			close(aux->command->io[STDIN_FILENO]);
		if (aux->command->io[STDOUT_FILENO] != STDOUT_FILENO
			&& aux->command->io[STDOUT_FILENO] != -1)
			close(aux->command->io[STDOUT_FILENO]);
		aux = aux->next;
	}
}

static int	st_child_process(t_cmd_table *cmd_table,
		t_pushdown_automaton *parse_bot)
{
	char	**command;
	char	**env;

	command = cmd_table->command->parsed;
	if (is_terminal2(parse_bot->env_list, &command[0]))
	{
		st_dup(cmd_table);
		st_close_all_fds(cmd_table);
		env = ll_to_tab(parse_bot->env_list);
		execve(command[0], command, env);
		free(env);
	}
	else if (str_comp(command[0], "(Invalid)"))
		printf("SEAshell: %s: command not found\n", command[0]);
	automaton_destroy(parse_bot);
	cmdt_destroy(&cmd_table);
	exit(1);
}

static void	st_dup(t_cmd_table *cmd)
{
	int		io[2];

	io[STDIN_FILENO] = cmd->command->io[STDIN_FILENO];
	io[STDOUT_FILENO] = cmd->command->io[STDOUT_FILENO];
	dup2(io[STDIN_FILENO], STDIN_FILENO);
	dup2(io[STDOUT_FILENO], STDOUT_FILENO);
}
