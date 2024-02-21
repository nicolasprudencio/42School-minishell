/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:28:52 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:28:53 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_pushdown_automaton	*automaton_new(char **env)
{
	t_pushdown_automaton	*parse_bot;

	parse_bot = (t_pushdown_automaton *)mem_calloc(1,
			sizeof(t_pushdown_automaton));
	parse_bot->language = grammar_new();
	parse_bot->transition = automaton_transition_relation();
	parse_bot->starting_state = STD_NULL;
	parse_bot->current_state = parse_bot->starting_state;
	parse_bot->initial_symbol = str_dup("<COMMAND>");
	parse_bot->stack = stck_empty('A');
	stck_push_str(parse_bot->stack, parse_bot->initial_symbol);
	parse_bot->env_list = ll_new(env);
	return (parse_bot);
}

void	automaton_destroy(t_pushdown_automaton *parse_bot)
{
	grammar_end(parse_bot->language);
	free(parse_bot->transition);
	free(parse_bot->initial_symbol);
	stck_rmv(parse_bot->stack);
	ll_clear(&parse_bot->env_list);
	free(parse_bot);
}
