#include "libseas.h"

t_stack	*stack_new()
{
	t_stack	*output;
	t_dllist	*list;

	output = (t_stack *)mem_calloc(1, sizeof(t_stack));
	if (!output)
		return (NULL);
	list = dll_new(NULL);
	if (!list)
	{
		free(output);
		return (NULL);
	}
	output->top = list;
	output->bot = list;
	return (output);
}

void	stack_push(t_stack *stack, char *content)
{
	dll_add_back(stack->top, content);
	return ;
}

void	stack_pop(t_stack *stack)
{
	t_dllist	*temp;

	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	return ;
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
