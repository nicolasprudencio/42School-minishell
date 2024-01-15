#include "libseas.h"

static void	st_recursive_cases(t_production *input);

t_production	*grammar_define_productions()
{
	t_production	*output;

	output = (t_production *)mem_calloc(8, sizeof(t_production));
	if (!output)
		return (NULL);
	output[0].variable = "<COMMAND>";
	output[0].output = 
		str_split("<TERMINAL> <FLAG> <ARGUMENT> <SPECIAL> <PIPE>", ' ');
	output[1].variable = "<COMMAND>";
	output[1].output = str_split("<SPECIAL> <STRING> <PIPE>", ' ');
	st_recursive_cases(output);
	output[6].variable = "VALIDATE_TO_NULL";
	return (output);
}

static void	st_recursive_cases(t_production *input)
{
	input[2].variable = "<FLAG>";
	input[2].output = str_split("<FLAG> <FLAG>", ' ');
	input[3].variable = "<ARGUMENT>";
	input[3].output = str_split("<STRING> <FLAG> <ARGUMENT>", ' ');
	input[4].variable = "<SPECIAL>";
	input[4].output = str_split("<STRING> <SPECIAL>", ' ');
	input[5].variable = "<PIPE>";
	input[5].output = str_split("<COMMAND>", ' ');
}

void	grammar_free_productions(t_production *product)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if ((product[i]).output)
			grid_free((product[i]).output);
	}
	free(product);
}

//	output[].variable = "<>";
//	output[].output = str_split("<>", ' ');
