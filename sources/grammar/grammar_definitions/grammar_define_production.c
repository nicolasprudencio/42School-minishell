#include "libseas.h"

t_production	*grammar_define_productions()
{
	t_production	*output;

	output = (t_production *)mem_calloc(6, sizeof(t_production));
	if (!output)
		return (NULL);
	output[0].variable = "<COMMAND>";
	output[0].output = str_split("<TERMINAL> <FLAG> <ARGUMENT>", ' ');
	output[1].variable = "<FLAG>";
	output[1].output = str_split("<TERMINAL> <FLAG>", ' ');
	output[2].variable = "<FLAG>";
	output[2].output = NULL;
	output[3].variable = "<ARGUMENT>";
	output[3].output = str_split("<STRING> <ARGUMENT>", ' ');
	output[4].variable = "<ARGUMENT>";
	output[4].output = NULL;
	return (output);
}

void	grammar_free_productions(t_production *product)
{
	grid_free(product->output);
	free(product);
}

/*
COMMAND ::= TERMINAL FLAG ARGUMENT
FLAG ::= TERMINAL FLAG | NULL
ARGUMENT ::= STRING ARGUMENT | NULL
*/
