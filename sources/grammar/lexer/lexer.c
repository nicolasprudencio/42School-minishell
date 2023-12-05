/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/12/05 15:48:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int g_index;

int	is_terminal(char *line, t_dictionary *dict, int i)
{	
	g_index = -1;
	while(dict->terminals[++g_index])
			if (str_ncmp(dict->terminals[g_index], &line[i], str_len(dict->terminals[g_index])) == 0)
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
		i++;
		if (line[i] == '\0')
			return (NULL);
	}
	while (line[i])
	{
		if (is_terminal(&line[i], dict, i))
		{
			token_push_last(&tokens, token_push(dict, g_index));
			tokens_print_list(tokens);
		}
		i++;
	}
	return (tokens);
	// if (line[i] == '-')
	// {
	// 	while (is_alpha(line[i]))
	// 	{
	// 		token = 
	// 		i++
	// 	}
	// }
}

void	lex_token_free(t_token **tokens)
{
	t_token	*aux;

	if (tokens)
	{
		aux = *tokens;
		while (aux)
		{
			free(aux->value);
			free(aux->token_type);
			aux = aux->next;
		}
		free((*tokens));
	}
}
