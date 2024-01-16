#include "libseas.h"

void	automaton_find_state(t_pushdown_automaton *parse_bot,
		t_token **input)
{
	if (!str_comp(parse_bot->stack->top->as_str, "<COMMAND>"))
		parse_bot->current_state = 1;
	else if (!str_comp((*input)->token_type, "<PIPE>"))
		parse_bot->current_state = 3;
	else if (!str_comp((*input)->token_type, "<SPECIAL>"))
	{
		if (!str_comp((*input)->value, "<<"))
			parse_bot->current_state = 4;
		if (!str_comp((*input)->value, "<"))
			parse_bot->current_state = 5;
		if (!str_comp((*input)->value, ">"))
			parse_bot->current_state = 6;
		if (!str_comp((*input)->value, ">>"))
			parse_bot->current_state = 7;
	}
	else
		parse_bot->current_state = 0;
}
