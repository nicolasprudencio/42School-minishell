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

	temp = tokens;
	output = NULL;
	while (temp)
	{
		act = automaton_act(parse_bot, &temp);
		if (act == FALSE_INDEX)
		{
			printf("%s%s'%s'\n", "SEAshell: ",
					"syntax error near unexpected token ",
					temp->value);
			break ;
		}
		if (!automaton_cmdt_create(parse_bot, &output, temp))
			break ;
	}
	automaton_restart_stack(parse_bot);
	return (output);
}
