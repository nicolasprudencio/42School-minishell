#include "libseas.h"

int	cmd_add(t_cmd_table **cmd, t_token *token, int flag)
{
	if (flag)
	{
		printf("\t\t  | -----\033[1m ADD to CMD \033[0m-----\n");
		printf("\t\t  | ++ %s\n", token->value);
		printf("\t\t  |\n");
		(*cmd)->command->parsed =
			grid_add_element((*cmd)->command->parsed, token->value);
		if (!(*cmd)->command->parsed)
			return (FALSE);
	}
	if (!flag)
	{
		printf("\t\t  | -----\033[1m ADD to CMD \033[0m-----\n");
		printf("\t\t  | ++ %s\n", token->prev->value);
		printf("\t\t  |\n");
		(*cmd)->command->parsed =
			grid_add_element((*cmd)->command->parsed,
					token->prev->value);
		if (!(*cmd)->command->parsed)
			return (FALSE);
	}
	return (TRUE);
}
