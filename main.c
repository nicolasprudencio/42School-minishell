#include "libseas.h"

int	main(void)
{
	char	*rl_output;

	while (1)
	{
		rl_output = readline("shellsea~ ");
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			return (0);
		}
		free(rl_output);
	}
	return (0);
}
