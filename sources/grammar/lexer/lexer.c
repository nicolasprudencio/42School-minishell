/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/12/14 18:26:18 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_add_special(t_token **tokens, char *line);
static int	st_add_terminal(t_dictionary *dict,
		t_token **tokens, char *line);
static int	st_add_flag(t_token **tokens, char *line);
static int	st_add_string(t_token **tokens, char *line);

t_token	*lexer(char *line, t_dictionary *dict)
{
	int			i;
	t_token	*tokens;

	i = 0;
	tokens = NULL;
	while (line[i])
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
		content = (char *)mem_calloc(hold, sizeof(char));
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

	hold = -1;
	if (str_is_enclosed(line, '\"') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\"');
	else if (str_is_enclosed(line, '\''))
		hold = str_is_enclosed(line, '\'');
	else
		while (line[hold] && !is_space(line[++hold]))
			;
	i = -1;
	content = (char *)mem_calloc(hold, sizeof(char));
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

