#include "libseas.h"

static int	st_pipe_validate(t_pushdown_automaton *parse_bot, 
		t_token **input);

void	automaton_find_state(t_pushdown_automaton *parse_bot,
		t_token **input)
{
	if (!str_comp(parse_bot->stack->top->as_str, "<COMMAND>") &&
			!(*input)->prev)
		parse_bot->current_state = 1;
	else if (st_pipe_validate(parse_bot, input) && (*input)->next)
		parse_bot->current_state = 2;
	else if (st_pipe_validate(parse_bot, input))
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

static int	st_pipe_validate(t_pushdown_automaton *parse_bot, 
		t_token **input)
{
	if (!str_comp((*input)->token_type, "<PIPE>") 
				&& !str_comp(parse_bot->stack->top->as_str,
					"<PIPE>"))
		return (TRUE);
	return (FALSE);
}
