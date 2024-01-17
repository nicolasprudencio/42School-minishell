#include "libseas.h"

int	automaton_cmdt_create(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	if (parse_bot->current_state == 1)
	{
		if (!automaton_cmd_create(cmd_table, token))
			return (FALSE);
	}
	else if (parse_bot->current_state == 2)
	{
		if (!automaton_cmd_create(cmd_table, token))
			return (FALSE);
//		if (!automaton_cmd_pipe(cmd_table))
//			return (FALSE);
	}
//	else if (parse_bot->current_state == 3)
//	else if (parse_bot->current_state == 4)
//	else if (parse_bot->current_state == 5)
//	else if (parse_bot->current_state == 6)
//	else if (parse_bot->current_state == 7)
//	else if (parse_bot->current_state == 8)
	return (TRUE);
}

