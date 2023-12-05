/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_print_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:48 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/05 15:56:34 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	tokens_print_list(t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	while (aux)
	{
		fp_printf("%s | ", aux->token_type);
		fp_printf("%s\n", aux->value);
		aux = aux->next;
	}
}