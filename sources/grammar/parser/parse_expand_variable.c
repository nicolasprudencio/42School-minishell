#include "libseas.h"

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
