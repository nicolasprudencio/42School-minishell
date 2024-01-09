#include "libseas.h"

t_production	*grammar_define_productions()
{
	t_production	*output;

	output = (t_production *)mem_calloc(6, sizeof(t_production));
	if (!output)
		return (NULL);
	output[0].variable = "<COMMAND>";
	output[0].output = str_split("<TERMINAL> <FLAG> <ARGUMENT>", ' ');
	output[1].variable = "<TERMINAL>";
	output[1].output = NULL;
	output[2].variable = "<FLAG>";
	output[2].output = str_split("<FLAG> <FLAG>", ' ');
	output[3].variable = "<FLAG>";
	output[3].output = NULL;
	output[4].variable = "<ARGUMENT>";
	output[4].output = str_split("<STRING> <ARGUMENT>", ' ');
	output[5].variable = "<ARGUMENT>";
	output[5].output = NULL;
	output[6].variable = "<STRING>";
	output[6].output = NULL;
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
	
//	output[].variable = "<>";
//	output[].output = str_split("<>", ' ');
