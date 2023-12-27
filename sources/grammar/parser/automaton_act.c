#include "libseas.h"

char	*automaton_act(t_pushdown_atomaton *robot, t_token *input)
{
	int	action;
	char	*stack_top = robot->stack->top->as_str;

	action = automaton_find_transition(robot, input->token_type, stack_top);
	if (action == -1)
		return (NULL);
	stack_pop(robot->stack);
	stack_rpush_tab(robot->stack,
			(robot->language->production[action])->output);
	return (stack_top);
}
