#include "libseas.h"

int	automaton_cmdt_create(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	if (parse_bot->current_state == 1)
	{
		if (!automaton_cmd_create(cmd_table, token->value))
			return (FALSE);
	}
//	else if (parse_bot->current_state == 2)
//	{
//		if(!automaton_cmd_add(cmd_table, token->value))
//			return (FALSE);
//	}
//	else if (parse_bot->current_state == 3)
		// create new pipe
//	else if (parse_bot->current_state == 4)
		// get input from heredoc
//	else if (parse_bot->current_state == 5)
		// input redirection
//	else if (parse_bot->current_state == 6)
		// output redirection
//	else if (parse_bot->current_state == 7)
		// output append
	return (TRUE);
}

