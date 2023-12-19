/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_push_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:39:29 by fpolaris          #+#    #+#             */
/*   Updated: 2023/12/19 10:39:35 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	token_push_last(t_token **tokens, t_token *new)
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
