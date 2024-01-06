#include "libseas.h"

int	automaton_act(t_pushdown_automaton *robot, t_token *input)
{
	int	action;
	char	*stack_top = robot->stack->top->as_str;

	action = automaton_find_transition(robot, input->token_type, stack_top);
	stack_pop(robot->stack);
	if (action != FALSE_INDEX)
		stack_rpush_tab(robot->stack,
				(robot->language->production[action]).output);
	return (action);
}
