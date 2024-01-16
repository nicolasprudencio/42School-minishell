#include "libseas.h"

int	automaton_cmd_add(t_cmd_table **cmd, char *value)
{
	printf("\t\t  | -----\033[1m ADD to CMD \033[0m-----\n");
	printf("\t\t  | ++ %s\n", value);
	printf("\t\t  |\n");
	(*cmd)->command->parsed = grid_add_element((*cmd)->command->parsed,
			value);
	if (!(*cmd)->command->parsed)
		return (FALSE);
	return (TRUE);
}
