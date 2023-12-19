#include "libseas.h"

static int	st_add_special(t_token **tokens, char *line);
static int	st_add_terminal(t_dictionary *dict,
		t_token **tokens, char *line);
static int	st_add_flag(t_token **tokens, char *line);
static int	st_add_string(t_token **tokens, char *line);

t_token	*lexer(char *line, t_dictionary *dict)
{
	int			i;
	int			len;
	t_token	*tokens;

	i = 0;
	tokens = NULL;
	len = str_len(line);
	while (i < len)
	{
		while (is_space(line[i]))
				i++;
		if (line[i] == '|')
		{
			token_push_last(&tokens, token_new("|", "<PIPE>"));
			i++;
		}
		else if (is_terminal(dict, &line[i]) != FALSE_INDEX)
			i += st_add_terminal(dict, &tokens, &line[i]);
		else if (is_flag(&line[i]) != FALSE_INDEX)
			i += st_add_flag(&tokens, &line[i]);
		else if (line[i] == '<' || line[i] == '>')
			i += st_add_special(&tokens, &line[i]);
		else
			i += st_add_string(&tokens, &line[i]);
	}
	return (tokens);
}

static int	st_add_terminal(t_dictionary *dict, t_token **tokens, char *line)
{
	int	hold;

	hold = is_terminal(dict, line);
	if (hold != FALSE_INDEX)
	{
		token_push_last(tokens,
				token_new(dict->terminals[hold], "<TERMINAL>"));
		return (str_len(dict->terminals[hold]));
	}
	return (FALSE_INDEX);
}

static int	st_add_flag(t_token **tokens, char *line)
{
	int		hold;
	int		i;
	char	*content;

	hold = -1;
	if (line[++hold] == '-')
	{
		while (is_alpha(line[++hold]))
			;
		content = (char *)mem_calloc(hold + 1, sizeof(char));
		i = -1;
		while (++i < hold)
			content[i] = line[i];
		token_push_last(tokens, token_new(content, "<FLAG>"));
		free(content);
		return (hold);
	}
	return (FALSE_INDEX);
}

static int	st_add_string(t_token **tokens, char *line)
{
	int		hold;
	int		i;
	char	*content;

	hold = 0;
	if (!line[hold])
		return (1);
	if (str_is_enclosed(line, '\"') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\"');
	else if (str_is_enclosed(line, '\'') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\'');
	else
		while (line[hold] && !is_space(line[++hold]))
			;
	i = -1;
	content = (char *)mem_calloc(hold + 1, sizeof(char));
	while (++i < hold)
		content[i] = line[i];
	token_push_last(tokens, token_new(content, "<STRING>"));
	free(content);
	return (hold);
}

static int	st_add_special(t_token **tokens, char *line)
{
	if (line[0] == '<')
	{
<<<<<<< HEAD
		if (line[1] == '<')
		{
			token_push_last(tokens, token_new("<<", "<SPECIAL>"));
			return (2);
		}
		token_push_last(tokens, token_new("<", "<SPECIAL>"));
		return (1);
=======
		while (*tokens)
		{
			aux = (*tokens)->next;
			if ((*tokens)->value)
				free((*tokens)->value);
			if ((*tokens)->token_type)
				free((*tokens)->token_type);
			free(*tokens);
			*tokens = aux;
		}
>>>>>>> 78f7d26564ab0510d0009da563e529346e20b32f
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

