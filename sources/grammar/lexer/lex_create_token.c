/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_create_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:47:35 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/05 16:09:10 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_token *token_push(char *value, char *type)
{
	t_token *token;

	token = mem_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->token_type = str_dup(type);
	token->value = str_dup(value);
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
	new->prev = aux;
	aux->next = new;
}