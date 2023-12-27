#include "libseas.h"

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
	return (FALSE_INDEX);
}
