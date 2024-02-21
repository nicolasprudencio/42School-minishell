/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_restart_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:29:04 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:29:05 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	automaton_restart_stack(t_pushdown_automaton *parse_bot)
{
	if (stck_is_empty(parse_bot->stack))
		return (FALSE);
	else
	{
		stck_rmv(parse_bot->stack);
		parse_bot->stack = stck_empty('a');
		stck_push_str(parse_bot->stack, parse_bot->initial_symbol);
	}
	return (TRUE);
}
