/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:29:43 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:29:45 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_cmd_table	*parser(t_pushdown_automaton *parse_bot, t_token *tokens)
{
	t_cmd_table	*output;
	t_token		*temp;
	int			act;

	temp = tokens;
	output = NULL;
	while (temp)
	{
		act = automaton_act(parse_bot, &temp);
		if (act == FALSE_INDEX)
		{
			printf("%s '%s'\n", STD_ERROR, temp->value);
			break ;
		}
		if (!cmdt_create(parse_bot->current_state, &output, temp))
			break ;
	}
	automaton_restart_stack(parse_bot);
	return (output);
}
