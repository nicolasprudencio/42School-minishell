/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/12/12 21:42:39 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int g_index;

// int	is_terminal(char *line, t_dictionary *dict)
// {	
// 	g_index = -1;
// 	while(dict->terminals[++g_index])
// 		if (str_comp_upto(line, dict->terminals[g_index],'|') == 0
// 			|| str_comp_upto(line, dict->terminals[g_index], ' ') == 0)
// 			return (TRUE);	
// 	return (FALSE);
// }

int	is_terminal(char *line, t_dictionary *dict)
{	
	g_index = -1;
	while(dict->terminals[++g_index])
		if (str_comp_upto(line, dict->terminals[g_index],'|') == 0
			|| str_comp_upto(line, dict->terminals[g_index], ' ') == 0)
			return (g_index);	
	return (FALSE_INDEX);
}

int	is_flag(char *line, t_dictionary *dict)
{
	g_index = -1;
	while (dict->variables[++g_index])
		if (str_comp_upto(line, dict->variables[g_index], '|') == 0
		|| str_comp_upto(line, dict->variables[g_index], ' '))
			return (TRUE);
	return (FALSE);
}

static int check_terminal(t_token **tokens, char *line, t_dictionary *dict)
{	
	int	i;
	int	term;
	
	i = 0;
	term = is_terminal(line, dict);
	// printf("whats happening: %i\n", term);
	if (term != FALSE_INDEX)
	{
		token_push_last(tokens, token_push(dict->terminals[g_index], "<TERMINAL>"));
		return (term);
	}
	return (FALSE_INDEX);
}

t_token *lex_core(char *line, t_dictionary *dict)
{	
	int		i;
	int		valid_index;
	t_token	*tokens;
	
	i = -1;
	tokens = NULL;
	while (is_space(line[++i]))
	{
		if (line[i] == '\0')
			return (NULL);
	}
	while (line[i])
	{	
		// the error consists in the case we dont use the '&line[i]' all time we passes at check_terminal function finds the same terminal index
		valid_index = check_terminal(&tokens, &line[i], dict);
		if (valid_index != FALSE_INDEX)
			i += str_len(dict->terminals[valid_index]);;
		if (line[i] == '-')
		{
			while (is_alpha(line[++i]))
			{
				if (is_flag(&line[i], dict))
					token_push_last(&tokens, token_push(dict->variables[g_index], "<FLAG>"));
			}
		}
		i++;
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
