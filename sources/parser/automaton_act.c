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
	int		act;
	char	*stack_top;

	stack_top = parse_bot->stack->top->as_str;
	act = automaton_find_transition(parse_bot, *input, stack_top);
	automaton_find_state(parse_bot, input);
	if (!str_comp((*input)->token_type, parse_bot->stack->top->as_str))
		(*input) = (*input)->next;
	if (act != FALSE_INDEX)
	{
		stck_pop(parse_bot->stack);
		stck_rpush_tab(parse_bot->stack,
				(parse_bot->language->production[act]).output);
	}
	return (act);
}
