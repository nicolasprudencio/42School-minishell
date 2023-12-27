#include "libseas.h"

int	*automaton_astates(int *states)
{
	int	*output;

	output = (int *)mem_calloc(1, sizeof(int));
	if (!output)
		return (NULL);
	output[0] = 1;
	return (output);
}
