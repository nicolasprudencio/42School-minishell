/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/12/07 19:50:31 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int g_index;

int	is_terminal(char *line, t_dictionary *dict)
{	
	g_index = -1;
	while(dict->terminals[++g_index])
			if (str_ncmp(dict->terminals[g_index], line, str_len(dict->terminals[g_index])) == 0)
				return (TRUE);
	return (FALSE);
}

int	is_flag(char *line, t_dictionary *dict)
{
	g_index = -1;
	while (dict->variables[++g_index])
		if (str_ncmp(dict->variables[g_index], line, str_len(dict->variables[g_index])) == 0)
			return (TRUE);
	return (FALSE);
}

t_token *lex_core(char *line, t_dictionary *dict)
{	
	int		i;
	t_token	*tokens;
	
	i = 0;
	tokens = NULL;
	while (is_space(line[i]))
	{	
		if (line[i] == '\0')
			return (NULL);
		i++;	
	}
	while (line[i])
	{
		if (is_terminal(&line[i], dict))
			token_push_last(&tokens, token_push(dict->terminals[g_index], "terminal"));
		if (line[i] == '-')
		{
			while (is_alpha(line[++i]))
			{
				if (is_flag(&line[i], dict))
					token_push_last(&tokens, token_push(dict->variables[g_index], "variable"));
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
