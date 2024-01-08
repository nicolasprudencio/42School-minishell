#include "libseas.h"

int	automaton_act(t_pushdown_automaton *robot, t_token *input)
{
	int	action;
	char	*stack_top = robot->stack->top->as_str;

	action = automaton_find_transition(robot, input->token_type, stack_top);
	put_dll(robot->stack->top, 1);
	stck_pop(robot->stack);
	put_dll(robot->stack->top, 1);
	if (action != FALSE_INDEX)
		stck_rpush_tab(robot->stack,
				(robot->language->production[action]).output);
	put_dll(robot->stack->top, 1);
	return (action);
}
