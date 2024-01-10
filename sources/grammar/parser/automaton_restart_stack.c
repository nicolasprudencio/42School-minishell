#include "libseas.h"

int	automaton_restart_stack(t_pushdown_automaton *parse_bot)
{
	if (stck_is_empty(parse_bot->stack))
			return (FALSE);
	else
	{
		stck_rmv(parse_bot->stack);
		parse_bot->stack = stck_empty('a');
		stck_push_str(parse_bot->stack, parse_bot->initial_symbol);
	}
	return (TRUE);
}
