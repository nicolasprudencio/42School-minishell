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

t_cmd_table	*parser(t_pushdown_automaton *parse_bot, t_token *tokens)
{
	t_cmd_table	*output;
	t_token		*temp;
	int	act;
	int	i;

	i = 0;
	output = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
	temp = tokens;
	printf("\033[1m{ O - o }\033[0m\t <| parsing process initializing\n");
	while (temp)
	{
		act = automaton_act(parse_bot, &temp);
		if (act == FALSE_INDEX)
		{
			free(output);
			return (NULL);
		}
	}
	output->command = (t_command *)mem_calloc(1, sizeof(t_command));
	output->command->parsed = automaton_find_command(tokens);
	output->command->io[0] = 1;
	output->command->io[1] = 1;
	automaton_restart_stack(parse_bot);
	return (output);
}
