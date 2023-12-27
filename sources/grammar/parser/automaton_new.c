#include "libseas.h"

t_pushdown_automaton	*automaton_new(t_dictionary *language)
{
	t_pushdown_automaton	*parse_bot;

	parse_bot->states = automaton_states(language);
	parse_bot->input_alphabet = language->terminals;
	parse_bot->stack_alphabet = language->variables;
	parse_bot->transition = automaton_transition_relation(language);
	parse_bot->starting_state = states[0];
	parse_bot->initial_symbol = "<COMMAND>";
	parse_bot->accepting_states = automaton_astates(language, states);
	parse_bot->stack = stack_new("<COMMAND>");
}

