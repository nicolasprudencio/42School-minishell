/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:29:52 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:52 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	automaton_act(t_pushdown_automaton *parse_bot, t_token **input)
{
	int	act;
	char	*stack_top = parse_bot->stack->top->as_str;

	act = automaton_find_transition(parse_bot,
			*input->token_type, stack_top);
	printf("\t\t  | input info: %s %s\n", *input->value, *input->token_type);
	printf("\t\t  | action found: %i\n\t\t  | stack info:\n", act);
	put_dll(parse_bot->stack->top, 1);
	if (!str_comp())
	if (act != FALSE_INDEX)
	{
		printf("\t\t  | taking action...\n");
		stck_pop(parse_bot->stack);
		stck_rpush_tab(parse_bot->stack,
				(parse_bot->language->production[act]).output);
	}
	printf("\t\t  | stack information:\n");
	put_dll(parse_bot->stack->top, 1);
	return (act);
}
