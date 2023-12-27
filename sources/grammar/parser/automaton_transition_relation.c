#include "libseas.h"

t_relation	*automaton_transition_relation(t_dictionary *language)
{
	t_relation	*output;

	output = (t_relation *)mem_calloc(5, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = {"<TERMINAL>", "<COMMAND>"};
	output[1] = {"<TERMINAL>", "<FLAG>"};
	output[2] = {"<STRING>", "<FLAG>"};
	output[3] = {"<STRING>", "<ARGUMENT>"};
	output[4] = {"<TERMINAL>", "<ARGUMENTS>"};
	return (output);
}
