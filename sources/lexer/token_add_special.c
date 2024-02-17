#include "libseas.h"

int	token_add_special(t_token **tokens, char *line)
{
	if (line[0] == '<')
	{
		if (line[1] == '<')
		{
			token_push_last(tokens, token_new("<<", "<SPECIAL>"));
			return (2);
		}
		token_push_last(tokens, token_new("<", "<SPECIAL>"));
		return (1);
	}
	else if (line[0] == '>')
	{
		if (line[1] == '>')
		{
			token_push_last(tokens, token_new(">>", "<SPECIAL>"));
			return (2);
		}
		token_push_last(tokens, token_new(">", "<SPECIAL>"));
		return (1);
	}
	return (FALSE_INDEX);
}
