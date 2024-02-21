/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_find_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:26:42 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:26:43 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	**automaton_find_command(t_token *tokens)
{
	char	**output;

	output = (char **)mem_calloc(1, sizeof(char *));
	while (tokens && str_comp(tokens->token_type, "<PIPE>") != 0)
	{
		output = grid_add_element(output, tokens->value);
		tokens = tokens->next;
	}
	return (output);
}
