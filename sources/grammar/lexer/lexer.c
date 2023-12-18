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

int g_index;
/*
static int	check_terminal(t_token **tokens, char *line, t_dictionary *dict)
{	
	int	term;
	
	term = is_terminal(line, dict);
	// printf("whats happening: %i\n", term);
	if (term != FALSE_INDEX)
	{
		token_push_last(tokens, token_push(dict->terminals[g_index], "<TERMINAL>"));
		return (term);
	}
	return (FALSE_INDEX);
}

static int	check_flag(t_token **tokens, char *line, t_dictionary *dict)
{
	int	flag;

	flag = is_flag(&line[0], dict);
	if (flag != FALSE_INDEX)
	{
		token_push_last(tokens, token_push(dict->variables[g_index], "<FLAG>"));
		return (flag);
	}
	return (FALSE_INDEX);
}

static int	check_special(t_token **tokens, char *line, t_dictionary *dict)
{
	int	spec;

	spec = is_special(&line[0], dict);
	if (spec != FALSE_INDEX)
	{
		token_push_last(tokens, token_push(dict->variables[g_index], "<SPECIAL>"));
		return (spec);
	}
	return (FALSE_INDEX);
}
*/

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
	if (line[++hold] == '\"')
	{
		while (line[++hold] && line[hold] != '\"')
			;
		if (!line[hold])
			return (-2);
		hold++;
	}
	else if (line[hold] == '\'')
	{
		while (line[++hold] && line[hold] != '\'')
			;
		if (!line[hold])
			return (-2);
		hold++;
	}
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

t_token	*lex_core(char *line, t_dictionary *dict)
{
	int	i;
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
/*
t_token *lex_core(char *line, t_dictionary *dict)
{
	int		i;
	int		valid_index;
	char	*str_aux;
	t_token	*tokens;
	
	i = -1;
	tokens = NULL;
	if (!is_alpha(line[0]) && !is_space(line[0]))
		return (NULL);
	// while (is_space(line[++i]))
	// {
	// 	if (line[i] == '\0')
	// 		return (NULL);
	// }
	while (line[i])
	{	
		valid_index = check_terminal(&tokens, &line[i], dict);
		if (valid_index != FALSE_INDEX)
			i += str_len_upto(&line[i], ' ');

		valid_index = check_flag(&tokens, &line[i], dict);
		if (valid_index != FALSE_INDEX)
			i += str_len(dict->variables[valid_index]) + 1;
		if (str_aux)
			line = str_aux;
		str_aux = str_find_char(&line[i], '|', 1);
		if (str_aux)
			line = str_aux;
		else
			line = str_find_char(&line[i], '\0', 1);	
	}
	tokens_print_list(tokens);
	return (tokens);
}
*/
void	lex_token_free(t_token **tokens)
{
	t_token	*aux;

	if (tokens)
	{
		while (*tokens)
		{
			aux = (*tokens)->next;
			if ((*tokens)->value)
				free((*tokens)->value);
			if ((*tokens)->token_type)	
				free((*tokens)->token_type);
			free((*tokens));
			*tokens = aux;
		}

	}
}
