#include "libfpp.h"

t_dictionary	*grammar_new();
{
	t_dictionary	*seas_script;

	seas_script = (t_dictionary *)mem_calloc(1,
			sizeof(t_dictionary));
	seas_script->variable = grammar_define_variables();
	seas_script->terminal = grammar_define_terminals();
	seas_script->production = grammar_define_product();
	seas_script->start = grammar_define_start();
	
	return (seas_script);
}

void	grammar_end(t_dictionary *seas_script)
{
	free(seas_script);
}
