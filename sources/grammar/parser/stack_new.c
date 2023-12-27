#include "libseas.h"

t_stack	*stack_new(char	**initial_value)
{
	t_stack	*output;

	output = (t_stack *)mem_calloc(1, sizeof(t_stack));
	if (!output)
		return (NULL);
	output->top = (t_dllist *)mem_calloc(1, sizeof(t_dllist));
	output->top->as_str = initial_value;
	output->bot = top;
}
