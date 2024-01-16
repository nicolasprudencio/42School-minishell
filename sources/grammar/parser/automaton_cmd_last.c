#include "libseas.h"

void	automaton_cmd_last(t_cmd_table **last, t_cmd_table **cmd_table)
{
	*last = *cmd_table;
	while (*last && (*last)->next)
		*last = (*last)->next;
}
