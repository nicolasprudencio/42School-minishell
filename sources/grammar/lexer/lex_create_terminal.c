/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_create_terminal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:47:35 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/05 16:00:20 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_token *token_push(t_dictionary *dict, int g_index)
{
	t_token *token;

	token = mem_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->token_type = str_dup("terminal");
	token->value = str_dup(dict->terminals[g_index]);
	token->next = NULL;
	return (token);
}

void token_push_last(t_token **tokens, t_token *new)
{	
	t_token	*aux;

	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	aux = *tokens;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}