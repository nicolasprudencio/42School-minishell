/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:08:53 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:08:55 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_check_input(char *input);

int	exec_exit(t_pushdown_automaton *parse_bot, t_cmd_table *cmd)
{
	int	exit_status;
	int	argument_count;

	if (!cmd)
	{
		automaton_destroy(parse_bot);
		put_endl("exit", 2);
		exit(0);
	}
	if (cmd->next)
		return (1);
	argument_count = grid_len(cmd->command->parsed);
	if (argument_count > 2)
	{
		put_endl("SEAshell: exit: too many arguments", 2);
		return (1);
	}
	put_endl("exit", 2);
	if (argument_count == 2)
		exit_status = st_check_input(cmd->command->parsed[1]);
	else
		exit_status = 0;
	automaton_destroy(parse_bot);
	cmdt_destroy(&cmd);
	exit(exit_status);
}

static int	st_check_input(char *input)
{
	if (!str_is_digit(input))
	{
		printf("SEAshell: exit: %s: numeric argument required\n",
			input);
		return (2);
	}
	return (conv_atoi(input));
}
