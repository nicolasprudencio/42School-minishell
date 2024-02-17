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

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot)
{
	t_cmd_table	*aux;
	int			status;
	int			cmd_quantity;
	int			current_cmd;

	current_cmd = -1;
	cmd_quantity = 0;
	aux = *cmd_table;
	while (aux)
	{
		cmd_quantity++;
		aux = aux->next;
	}
	aux = *cmd_table;
	while (cmd_quantity--)
	{
		if (is_builtin(parse_bot->language,
				aux->command->parsed[0]) != FALSE_INDEX)
			status = st_run_builtin(aux->command, 
					parse_bot->env_list);
		else
			status = exec_open_process(cmd_table, ++current_cmd, parse_bot);
	}
	return (status);
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
