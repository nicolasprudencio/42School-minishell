/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_find_transition.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:29:37 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:38 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	automaton_find_transition(t_pushdown_automaton *robot,
		t_token *token, char *stack_top)
{
	int	i;

	i = -1;
	while (robot->transition[++i].input)
	{
		if (!str_comp(token->token_type, robot->transition[i].input)
				&& !str_comp(stack_top,
					robot->transition[i].stack_top))
		{
			if (i >= 8)
				return (8);
			else
				return (i);
		}
	}
	return (FALSE_INDEX);
}
