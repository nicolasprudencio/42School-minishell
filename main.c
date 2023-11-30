#include "libseas.h"

int	main(void)
{
	char	*rl_output;
	char	**terminal;

	terminal = grammar_define_terminals();
	fp_printf("terminals = %s\n", terminal[0]);
	while (1)
	{
		rl_output = readline("SEAshell~ ");

		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			return (0);
		}
		free(rl_output);
	}
	return (0);
}
