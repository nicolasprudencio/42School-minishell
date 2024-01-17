#include "libseas.h"

static int	st_pipe_validate(t_pushdown_automaton *parse_bot, 
		t_token **input);

void	automaton_find_state(t_pushdown_automaton *parse_bot,
		t_token **input)
{
	if (!str_comp(parse_bot->stack->top->as_str, "<COMMAND>") &&
			!(*input)->prev)
		parse_bot->current_state = NEW_CMD;
	else if (st_pipe_validate(parse_bot, input) && (*input)->next)
		parse_bot->current_state = PIPE_TO_CMD;
	else if (st_pipe_validate(parse_bot, input))
		parse_bot->current_state = PIPE_EMPTY;
	else if (!str_comp((*input)->token_type, "<SPECIAL>"))
	{
		if (!(*input)->next || str_comp((*input)->next->value,
					"<STRING>"))
			parse_bot->current_state = HEREDOC_WRONG;
		else if (!str_comp((*input)->value, "<<"))
			parse_bot->current_state = HEREDOC;
		else if (!str_comp((*input)->value, "<"))
			parse_bot->current_state = INPUT_REDIR;
		else if (!str_comp((*input)->value, ">"))
			parse_bot->current_state = OUTPUT_REDIR;
		else if (!str_comp((*input)->value, ">>"))
			parse_bot->current_state = APPEND;
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
