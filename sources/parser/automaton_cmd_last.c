#include "libseas.h"

void	cmd_last(t_cmd_table **last, t_cmd_table **cmd_table)
{
	*last = *cmd_table;
	while (*last && (*last)->next)
	{
		(*last)->next->prev = (*last);
		*last = (*last)->next;
	}
}
