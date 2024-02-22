/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_last_is_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:19:49 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:19:50 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	token_last_is_pipe(t_token **tokens)
{
	t_token	*temp;

	temp = tokens[0];
	while (temp->next)
		temp = temp->next;
	if (str_comp(temp->token_type, "<PIPE>"))
		return (TRUE);
	return (FALSE);
}
