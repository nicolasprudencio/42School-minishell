#include "libseas.h"

int	automaton_cmd_append(t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;
	char	*path;

	path = token->value;
	automaton_cmd_last(&last, cmd_table);
	if (access(path, F_OK == FALSE_INDEX))
	{
		last->command->io[STDOUT_FILENO] = open(path, O_CREAT);
		printf("\t\t  | opened fd: %i for file %s\n",
				last->command->io[STDOUT_FILENO], path);
		return (TRUE);
	}
	if (access(path, W_OK) == FALSE_INDEX)
	{
		printf("SEAshell: %s: Permission denied\n", path);
		return (FALSE);
	}
	if (last->command->io[STDOUT_FILENO] != STDOUT_FILENO)
		close(last->command->io[STDIN_FILENO]);
	last->command->io[STDOUT_FILENO] = open(path, O_WRONLY | O_APPEND);
	printf("\t\t  | opened fd: %i for file %s\n",
			last->command->io[STDOUT_FILENO], path);
	if (!last->command->io[STDOUT_FILENO])
	{
		printf("SEAshell: %s: Failed to open\n", path);
		return (FALSE);
	}
	return (TRUE);
}
