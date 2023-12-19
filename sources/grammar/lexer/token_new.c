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

t_token	*token_new(char *value, char *type)
{
	t_token	*token;

	token = mem_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->token_type = str_dup(type);
	token->value = str_dup(value);
	token->next = NULL;
	return (token);
}

void	token_free(t_token **tokens)
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
