/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:30:37 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:30:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_cmd_table	*st_error(t_pushdown_automaton *parse_bot,
		t_cmd_table *to_free);

t_cmd_table	*parser(t_pushdown_automaton *parse_bot, t_token *tokens)
{
	t_cmd_table	*output;
	t_token		*temp;
	int	act;

	temp = tokens;
	output = NULL;
	printf("\033[1m{ O - o }\033[0m\t <| \033[1mparsing process initializing\033[0m\n");
	while (temp)
	{
		act = automaton_act(parse_bot, &temp);
		if (act == FALSE_INDEX)
		{
			free(output);
			automaton_restart_stack(parse_bot);
			return (st_error(parse_bot, output));
		}
		if (!automaton_cmdt_create(parse_bot, &output, temp))
			return (st_error(parse_bot, output));
			
	}
	automaton_restart_stack(parse_bot);
	return (output);
}

t_cmd_table	*st_error(t_pushdown_automaton *parse_bot, t_cmd_table *to_free)
{
	free(to_free);
	// free cmd_table if exists
	automaton_restart_stack(parse_bot);
	return (NULL);
}
