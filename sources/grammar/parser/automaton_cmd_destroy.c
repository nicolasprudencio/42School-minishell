#include "libseas.h"

void	automaton_cmdt_destroy(t_cmd_table **cmd_table)
{
	t_cmd_table	*aux1;
	t_cmd_table	*aux2;

	if (!(*cmd_table))
		return ;
	aux1 = (*cmd_table);
	printf("freeing command\n");
	while (aux1)
	{
		if (aux1->command)
		{
			free(aux1->command->parsed);
			free(aux1->command);
		}
		aux2 = aux1;
		aux1 = aux1->next;
		free(aux2);
	}
}
