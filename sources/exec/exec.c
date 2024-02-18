/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:36:07 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/17 02:19:49 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_run_builtin(t_command *cmd, t_llist *env);
static int	st_count_commands(t_cmd_table *cmd_table);
static void	st_go_to_next_command(t_cmd_table **cmd_table);

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot)
{
	int	status;
	int	cmd_quantity;

	cmd_quantity = st_count_commands(*cmd_table);
	while (cmd_quantity--)
	{
		if (is_builtin(parse_bot->language,
				(*cmd_table)->command->parsed[0]) != FALSE_INDEX)
			status = st_run_builtin((*cmd_table)->command, 
					parse_bot->env_list);
		else
			status = exec_open_process(cmd_table, parse_bot);
		st_go_to_next_command(cmd_table);
	}
	return (status);
}

static void	st_go_to_next_command(t_cmd_table **cmd_table)
{
	t_cmd_table *aux;

	aux = (*cmd_table);
	(*cmd_table) = (*cmd_table)->next;
	cmd_destroy(aux);
}

static int	st_count_commands(t_cmd_table *cmd_table)
{
	t_cmd_table	*aux;
	int			cmd_quantity;

	cmd_quantity = 0;
	aux = cmd_table;
	while (aux)
	{
		cmd_quantity++;
		aux = aux->next;
	}
	return (cmd_quantity);
}

static int	st_run_builtin(t_command *cmd, t_llist *env)
{
	if (!str_comp(cmd->parsed[0], "echo"))
		return (exec_echo(cmd->parsed, cmd->io[STDOUT_FILENO]));
	if (!str_comp(cmd->parsed[0], "cd"))
		return (exec_cd(cmd->parsed[1], &env));
//	if (!str_comp(cmd->parsed[0], "pwd"))
//	if (!str_comp(cmd->parsed[0], "export"))
//	if (!str_comp(cmd->parsed[0], "unset"))
//	if (!str_comp(cmd->parsed[0], "env"))
//	if (!str_comp(cmd->parsed[0], "exit"))
	return (1);
}
