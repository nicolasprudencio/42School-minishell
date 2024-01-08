#include "libseas.h"

t_pushdown_automaton	*automaton_new(t_dictionary *language)
{
	t_pushdown_automaton	*parse_bot;

	parse_bot = (t_pushdown_automaton *)mem_calloc(1,
			sizeof(t_pushdown_automaton));
	parse_bot->states = automaton_states();
	parse_bot->language = language;
	parse_bot->transition = automaton_transition_relation();
	parse_bot->starting_state = parse_bot->states[0];
	parse_bot->initial_symbol = str_dup("<COMMAND>");
	parse_bot->accepting_states = automaton_astates(parse_bot->states);
	parse_bot->stack = stack_new(parse_bot->initial_symbol);
	parse_bot->stack->top->as_str = (char *)parse_bot->initial_symbol;
	return (parse_bot);
}

