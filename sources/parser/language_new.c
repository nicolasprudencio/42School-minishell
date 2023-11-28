#include "libfpp.h"

t_context_free_grammar	*grammar_new();
{
	t_context_free_grammar	*seas_script;

	seas_script = (t_context_free_grammar *)mem_calloc(1,
			sizeof(t_context_free_grammar));
	seas_script->variable = NULL;
	seas_script->terminal = NULL;
	seas_script->production = NULL;
	seas_script->start = NULL;
	return (seas_script);
}

void	grammar_end(t_context_free_grammar *seas_script)
{
	free(seas_script);
}
