#include "libseas.h"

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
