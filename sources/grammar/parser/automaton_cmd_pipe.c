#include "libseas.h"

int	automaton_cmd_pipe(t_cmd_table **cmd_table)
{
	t_cmd_table	*last;
	t_command	*cmd_i;
	t_command	*cmd_o;
	int				pipefd[2];

	automaton_cmd_last(&last, cmd_table);
	if (pipe(pipefd))
		return (FALSE);
	cmd_i = last->command;
	cmd_o = last->prev->command;
	printf("\t\t  | new pipe [%i, %i]\n", pipefd[0], pipefd[1]);
	cmd_i->io[STDIN_FILENO] = pipefd[STDIN_FILENO];
	cmd_o->io[STDOUT_FILENO] = pipefd[STDOUT_FILENO];
	return (TRUE);
}
