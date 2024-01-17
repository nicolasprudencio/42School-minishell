#include "libseas.h"

static int	st_redirect_io(int state, t_cmd_table **cmd_table,
		t_token *token);

int	automaton_cmdt_create(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	if (parse_bot->current_state == NEW_CMD)
	{
		if (!automaton_cmd_create(cmd_table, token))
			return (FALSE);
	}
	if (!(st_redirect_io(parse_bot->current_state, cmd_table, token)))
		return (FALSE);
//	else if (parse_bot->current_state == 3)
//	else if (parse_bot->current_state == 4)
//	else if (parse_bot->current_state == 5)
//	else if (parse_bot->current_state == 6)
//	else if (parse_bot->current_state == 7)
//	else if (parse_bot->current_state == 8)
	return (TRUE);
}

static int	st_redirect_io(int state, t_cmd_table **cmd_table,
		t_token *token)
{
	if (state == PIPE_TO_CMD)
	{
		if (!automaton_cmd_create(cmd_table, token))
			return (FALSE);
		if (!automaton_cmd_pipe(cmd_table))
			return (FALSE);
	}
	return (TRUE);
}
