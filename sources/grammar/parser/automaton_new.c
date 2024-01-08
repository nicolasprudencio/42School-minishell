/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:29:56 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:57 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_pushdown_automaton	*automaton_new(t_dictionary *language)
{
	t_pushdown_automaton	*parse_bot;

	parse_bot = (t_pushdown_automaton *)mem_calloc(1,
			sizeof(t_pushdown_automaton));
	parse_bot->states = automaton_states();
	parse_bot->language = language;
	parse_bot->transition = automaton_transition_relation();
	parse_bot->starting_state = parse_bot->states[0];
	parse_bot->initial_symbol = str_dup("<COMMAND>");
	parse_bot->accepting_states = automaton_astates(parse_bot->states);
	parse_bot->stack = stck_new((void **)&parse_bot->initial_symbol, 'a');
	parse_bot->stack->top->as_str = (char *)parse_bot->initial_symbol;
	return (parse_bot);
}

