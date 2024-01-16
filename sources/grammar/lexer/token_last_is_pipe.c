#include "libseas.h"

int	token_last_is_pipe(t_token **tokens)
{
	t_token	*temp;

	temp = tokens[0];
	while (temp->next)
		temp = temp->next;
	if (str_comp(temp->token_type, "<PIPE>"))
			return (TRUE);
	return (FALSE);
}
