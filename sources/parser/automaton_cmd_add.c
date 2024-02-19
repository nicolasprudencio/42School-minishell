#include "libseas.h"

int	cmd_add(t_cmd_table **cmd, t_token *token, int flag)
{
	if (flag)
	{
		(*cmd)->command->parsed =
			grid_add_element((*cmd)->command->parsed, token->value);
		if (!(*cmd)->command->parsed)
			return (FALSE);
	}
	if (!flag)
	{
		(*cmd)->command->parsed =
			grid_add_element((*cmd)->command->parsed,
					token->prev->value);
		if (!(*cmd)->command->parsed)
			return (FALSE);
	}
	return (TRUE);
}
