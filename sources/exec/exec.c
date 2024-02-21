/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:36:07 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 10:07:35 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_count_commands(t_cmd_table *cmd_table);
static void	st_go_to_next_command(t_cmd_table **cmd_table);
static int	st_run_builtin(t_cmd_table *cmd, t_pushdown_automaton *parse_bot);

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot)
{
	int	status;
	int	cmd_quantity;

	cmd_quantity = st_count_commands(*cmd_table);
	while (cmd_quantity--)
	{
		if (is_builtin(parse_bot->language,
				(*cmd_table)->command->parsed[0]) != FALSE_INDEX)
			status = st_run_builtin(*cmd_table, 
					parse_bot);
		else if (str_comp((*cmd_table)->command->parsed[0], "(Invalid)"))
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

static int	st_run_builtin(t_cmd_table *cmd, t_pushdown_automaton *parse_bot)
{
	if (!str_comp(cmd->command->parsed[0], "echo"))
		return (exec_echo(cmd->command->parsed,
					cmd->command->io[STDOUT_FILENO]));
	if (!str_comp(cmd->command->parsed[0], "cd"))
		return (exec_cd(cmd->command->parsed[1], &parse_bot->env_list));
	if (!str_comp(cmd->command->parsed[0], "pwd"))
		return (get_pwd(cmd->command->io[STDOUT_FILENO]));
	if (!str_comp(cmd->command->parsed[0], "export"))
		return (exec_export(parse_bot->env_list, cmd->command));
	if (!str_comp(cmd->command->parsed[0], "unset"))
		return (exec_unset(&parse_bot->env_list, cmd->command->parsed));
	if (!str_comp(cmd->command->parsed[0], "env") && !cmd->command->parsed[1])
		return (exec_env(parse_bot->env_list, cmd->command->io[STDOUT_FILENO]));
	if (!str_comp(cmd->command->parsed[0], "exit") && !cmd->next)
		return (exec_exit(parse_bot, cmd));
	return (1);
}
