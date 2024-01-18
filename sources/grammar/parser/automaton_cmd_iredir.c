#include "libseas.h"

int	automaton_cmd_iredir(t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;
	char	*path;

	path = token->value;
	automaton_cmd_last(&last, cmd_table);
	if (access(path, F_OK == FALSE_INDEX))
	{
		printf("SEAshell: %s: No such file or directory\n", path);
		last->command->parsed[0] = "(Invalid)";
		return (FALSE);
	}
	if (access(path, R_OK) == FALSE_INDEX)
	{
		printf("SEAshell: %s: Permission denied\n", path);
		return (FALSE);
	}
	last->command->io[STDIN_FILENO] = open(path, O_RDONLY);
	if (!last->command->io[STDIN_FILENO])
	{
		printf("SEAshell: %s: Failed to open\n", path);
		return (FALSE);
	}
	printf("\t\t  | opened fd: %li for file: %s\n",
			last->command->io[STDIN_FILENO], path);
	return (TRUE);
}
