/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:19:31 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:19:32 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	token_add_special(t_token **tokens, char *line)
{
	if (line[0] == '<')
	{
		if (line[1] == '<')
		{
			token_push_last(tokens, token_new("<<", "<SPECIAL>"));
			return (2);
		}
		token_push_last(tokens, token_new("<", "<SPECIAL>"));
		return (1);
	}
	else if (line[0] == '>')
	{
		if (line[1] == '>')
		{
			token_push_last(tokens, token_new(">>", "<SPECIAL>"));
			return (2);
		}
		token_push_last(tokens, token_new(">", "<SPECIAL>"));
		return (1);
	}
	return (FALSE_INDEX);
}
