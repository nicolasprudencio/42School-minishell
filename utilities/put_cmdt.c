#include "libseas.h"

void	put_cmdt(t_cmd_table *cmd_table)
{
	printf("\t*--               COMMAND TABLE                  --*\n");
	printf("\t|                                                  |\n");
	printf("\t  %-15s\t%-15s\t%-15s  \n", "command","input", "output");
	while (cmd_table)
	{
		printf("\t  %-15s\t%-15i\t%-15i  \n",
				cmd_table->command->parsed[0],
				cmd_table->command->io[0],
				cmd_table->command->io[1]);
		cmd_table = cmd_table->next;
	}
	printf("\t|                                                  |\n");
	printf("\t*--                                              --*\n");
}