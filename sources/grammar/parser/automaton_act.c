#include "libseas.h"

char	*automaton_act(t_pushdown_atomaton *robot, t_token *input)
{
	int	action;
	char	*stack_top = robot->stack->top->as_str;

	action = automaton_find_transition(robot, input->token_type, stack_top);
	output = grid_add(output, 
	stack_pop(robot->stack);
	stack_rpush_tab(robot->stack,
			(robot->language->production[action])->output);
	return (stack_top);
}

void	stack_rpush_tab(t_stack *stack, char **input)
{
	int	i;

	i = -1;
	while (input[++i])
		;
	while (i > 0)
		stack_push(stack, input[i]);
	return ;
}

int	automaton_find_transition(t_pushdown_automaton *robot, char *token_type,
		char *stack_top)
{
	int	i;

	i = -1;
	while (robot->transition[i])
	{
		if (token_type == robot->transition[i][0]
				&& stack_top == robot->transition[i][1])
			return (i);
	}
	return (-1);
}
