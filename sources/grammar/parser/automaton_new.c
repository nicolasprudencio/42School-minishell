#include "seas.h"

t_pushdown_automaton	*automaton_new(t_dictionary *language)
{
	t_pushdown_automaton	*parse_bot;

	parse_bot->states = automaton_states(language);
	parse_bot->input_alphabet = language->terminals;
	parse_bot->stack_alphabet = language->variables;
	parse_bot->transition = automaton_transition_relation(language);
	parse_bot->starting_state = states[0];
	parse_bot->initial_symbol = "<COMMAND>";
	parsing_bot->accepting_states = automaton_astates(language, states);
}

t_relation	*automaton_transition_relation(t_dictionary *language)
{
	t_relation	*output;

	output = (t_relation *)mem_calloc(5, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = {"<TERMINAL>", "<COMMAND>"};
	output[1] = {"<TERMINAL>", "<FLAG>"};
	output[2] = {"<STRING>", "<FLAG>"};
	output[3] = {"<STRING>", "<ARGUMENT>"};
	output[4] = {"<TERMINAL>", "<ARGUMENTS>"};
	return (output);
}

int	*automaton_states(void)
{
	int	*output;

	output = (int *)mem_calloc(1, sizeof(int));
	if (!output)
		return (NULL);
	output[0] = 1;
	return (output);
}

int	*automaton_astates(int *states)
{
	int	*output;

	output = (int *)mem_calloc(1, sizeof(int));
	if (!output)
		return (NULL);
	output[0] = 1;
	return (output);
}

void	parse_expand_variable(t_dictionary *lang, t_stack *stack)
{
	char	*stack_top;
	int	var;

	stack_top = stack->top->as_str;
	var = is_variablie(lang, stack_top);
	if (var)
		stack_pop(stack);
	stack_rpush_tab((lang->production[var])->output);
}
