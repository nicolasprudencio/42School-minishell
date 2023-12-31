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
	output[1].output = str_split("<FLAG> <FLAG>", ' ');
	output[2].variable = "<ARGUMENT>";
	output[2].output = str_split("<STRING> <ARGUMENT>", ' ');
	output[3].variable = "<FLAG>";
	output[3].output = NULL;
	output[4].variable = "<ARGUMENT>";
	output[4].output = NULL;
	return (output);
}

void	grammar_free_productions(t_production *product)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if ((product[i]).output)
			grid_free((product[i]).output);
	}
	free(product);
}

/*
COMMAND ::= TERMINAL FLAG ARGUMENT
FLAG ::= FLAG FLAG | NULL
ARGUMENT ::= STRING ARGUMENT | NULL
*/
