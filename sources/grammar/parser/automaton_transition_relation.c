#include "libseas.h"

t_relation	*automaton_transition_relation(void)
{
	t_relation	*output;

	output = (t_relation *)mem_calloc(4, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = (t_relation){"<TERMINAL>", "<COMMAND>"};
	output[1] = (t_relation){"<FLAG>", "<FLAG>"};
	output[2] = (t_relation){"<ARGUMENT>", "<ARGUMENT>"};
	return (output);
}
