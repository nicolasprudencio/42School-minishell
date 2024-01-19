/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:34:38 by fpolaris          #+#    #+#             */
/*   Updated: 2023/12/19 10:34:40 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	put_token(t_token *tokens)
{
	while (tokens)
	{
		fp_printf("%15s | %s\n", tokens->token_type, tokens->value);
		tokens = tokens->next;
	}
}
