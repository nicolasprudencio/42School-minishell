#include "libseas.h"

static void	st_close_io(t_cmd_table **cmd);

void	automaton_cmdt_destroy(t_cmd_table **cmd_table)
{
	t_cmd_table	*aux1;
	t_cmd_table	*aux2;

	if (!(*cmd_table))
		return ;
	aux1 = (*cmd_table);
	while (aux1)
	{
		if (aux1->command)
		{
			st_close_io(&aux1);
			free(aux1->command->parsed);
			free(aux1->command);
		}
		aux2 = aux1;
		aux1 = aux1->next;
		free(aux2);
	}
}

static void	st_close_io(t_cmd_table **cmd)
{
	int	inp_fd;
	int	out_fd;

	inp_fd = (*cmd)->command->io[STDIN_FILENO];
	out_fd = (*cmd)->command->io[STDOUT_FILENO];

	if (inp_fd != STDIN_FILENO)
		close(inp_fd);
	if (out_fd != STDOUT_FILENO)
		close(out_fd);
}
