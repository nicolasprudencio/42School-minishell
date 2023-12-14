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

int	has_word(char *str)
{
	if ()
}

void	next_word(char *line)
{
	int	i;

	i = -1;
	while (line[++i])                                                                                   
}

t_token	*lex_core(char *line, t_dictionary *dict)
{
	int	i;
	t_token	*tokens;

	i = -1;
	tokens = NULL;
	while (next_word(&line[i]))
	{
		st_find_terms(&line[i], &i, &tokens);
		st_find_flags(&line[i], &i, &tokens);
		st_find_strig(&line[i], &i, &tokens);
		st_find_spcls(&line[i], &i, &tokens);
		if (line[i] == '|')
		{
			// add to tokens;
			i++;
		}
	}
}

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
