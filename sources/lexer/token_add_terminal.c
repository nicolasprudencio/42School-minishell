#include "libseas.h"

int	token_add_terminal(t_dictionary *dict, t_token **tokens,
		char *line)
{
	int	hold;

	hold = is_builtin(dict, line);
	if (hold != FALSE_INDEX)
	{
		if (*tokens && token_last_is_pipe(tokens)) 
			token_push_last(tokens,
				token_new(dict->terminals[hold],
					"<STRING>"));
		else
			token_push_last(tokens,
					token_new(dict->terminals[hold],
						"<TERMINAL>"));
		return (str_len(dict->terminals[hold]));
	}
	return (FALSE_INDEX);
}
