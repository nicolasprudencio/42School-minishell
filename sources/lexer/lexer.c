#include "libseas.h"

t_token	*lexer(char *line, t_pushdown_automaton *parse_bot)
{
	int			i;
	t_token	*tokens;

	i = 0;
	tokens = NULL;
	if (!line)
		return (NULL);
	while (line[i])
	{
		while (is_space(line[i]))
				i++;
		if (line[i] == '|')
		{
			token_push_last(&tokens, token_new("|", "<PIPE>"));
			i++;
		}
		else if (is_builtin(parse_bot->language, &line[i]) != FALSE_INDEX)
			i += token_add_terminal(parse_bot->language, &tokens, &line[i]);
		else if (is_flag(&line[i]) != FALSE_INDEX)
			i += token_add_flag(&tokens, &line[i]);
		else if (line[i] == '<' || line[i] == '>')
			i += token_add_special(&tokens, &line[i]);
		else if (line [i])
			i += token_add_string(&tokens, &line[i]);
	}
	return (tokens);
}
