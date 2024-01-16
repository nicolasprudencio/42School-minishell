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
			(*input)->token_type, stack_top);
	automaton_find_state(parse_bot, input);
	printf("\t\t  | input info\t %s\t%s\n",
			(*input)->value, (*input)->token_type);
	printf("\t\t  | stack info\t\t%s\n", 
			parse_bot->stack->top->as_str);
	printf("\t\t  | action\t \033[1m%i\033[0m\n",
			act);
	if (!str_comp((*input)->token_type,
				parse_bot->stack->top->as_str))
	{
		(*input) = (*input)->next;
		if (parse_bot->state == 0)
			parse_bot->state == 2;
	}
	printf("\t\t  | state\t \033[1m%i\033[0m\n",
			parse_bot->current_state);
	if (act != FALSE_INDEX)
	{
		printf("\t\t  | -----\033[1mtaking action\033[0m-----\n");
		stck_pop(parse_bot->stack);
		stck_rpush_tab(parse_bot->stack,
				(parse_bot->language->production[act]).output);
	}
	return (act);
}
