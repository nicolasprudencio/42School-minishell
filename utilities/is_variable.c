#include "libseas.h"

int	is_variable(t_dictionary *language, char *compare)
{
	int	i;

	i = -1;
	while (language->varibles[++i])
	{
		if (str_comp(language->variables[i], compare))
			return (i);
	}
	return (0);
}
