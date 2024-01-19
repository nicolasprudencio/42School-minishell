/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:36:07 by fpolaris          #+#    #+#             */
/*   Updated: 2024/01/19 12:36:08 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot)
{
	pid_t	process;

	while (*cmd_table)
	{
		process = fork();
		if (!process)
			return (FALSE);
		if (process == 0)
		{
			if (!st_child_process(cmd_table, parse_bot))
				return (FALSE);
		}
		else
		{
			*cmd_table = (*cmd_table)->next;
//			if (!st_parent_process(cmd_table, parse_bot))
//				return (FALSE);
		}
	}
	return (TRUE);
}

static int	st_child_process(t_command_table *cmd_table, 
		t_pushdown_automaton * parse_bot)
{
		
}
