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

	output = (t_relation *)mem_calloc(8, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = (t_relation){"<TERMINAL>", "<COMMAND>"};
	output[1] = (t_relation){"<TERMINAL>", "<TERMINAL>"};
	output[2] = (t_relation){"<FLAG>", "<FLAG>"};
	output[3] = (t_relation){"<STRING>", "<FLAG>"};
	output[4] = (t_relation){"<STRING>", "<ARGUMENT>"};
	output[5] = (t_relation){"<ARGUMENT>", NULL};
	output[6] = (t_relation){"<STRING>", "<STRING>"};
	return (output);
}

//	output[] = (t_relation){"<>", "<>"};
