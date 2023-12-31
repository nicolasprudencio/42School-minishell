/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_transition_relation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:30:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:30:33 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_relation	*automaton_transition_relation(void)
{
	t_relation	*output;

	output = (t_relation *)mem_calloc(4, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = (t_relation){"<TERMINAL>", "<COMMAND>"};
	output[1] = (t_relation){"<FLAG>", "<FLAG>"};
	output[2] = (t_relation){"<ARGUMENT>", "<ARGUMENT>"};
	return (output);
}
