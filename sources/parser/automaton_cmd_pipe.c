#include "libseas.h"

int	cmd_pipe(t_cmd_table **cmd_table)
{
	t_cmd_table	*last;
	t_command	*cmd_i;
	t_command	*cmd_o;
	int				pipefd[2];

	cmd_last(&last, cmd_table);
	if (pipe(pipefd))
		return (FALSE);
	cmd_i = last->command;
	cmd_o = last->prev->command;
	if (cmd_i->io[STDIN_FILENO] == STDIN_FILENO)
		cmd_i->io[STDIN_FILENO] = pipefd[STDIN_FILENO];
	else
		close(pipefd[STDIN_FILENO]);
	if (cmd_o->io[STDOUT_FILENO] == STDOUT_FILENO)
		cmd_o->io[STDOUT_FILENO] = pipefd[STDOUT_FILENO];
	else
		close(pipefd[STDOUT_FILENO]);
	return (TRUE);
}
