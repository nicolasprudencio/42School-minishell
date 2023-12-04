#include "libseas.h"

int	is_terminal(t_dictionary *language, char *compare)
{
	int	i;

	i = -1;
	while (language->terminals[++i])
	{
		if (str_comp(language->terminals[++i], compare) == 0)
			return (i);
	}
	return (0);
}
