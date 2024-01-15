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

static void	st_recursive_cases(t_relation *input);
static void	st_validate_to_null(t_relation *input);

t_relation	*automaton_transition_relation(void)
{
	t_relation	*output;

	output = (t_relation *)mem_calloc(17, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = (t_relation){"<TERMINAL>", "<COMMAND>"};
	output[1] = (t_relation){"<SPECIAL>", "<COMMAND>"};
	st_recursive_cases(output);
	st_validate_to_null(output);
	return (output);
}

static void	st_recursive_cases(t_relation *input)
{
	input[2] = (t_relation){"<FLAG>", "<FLAG>"};
	input[3] = (t_relation){"<STRING>", "<ARGUMENT>"};
	input[4] = (t_relation){"<SPECIAL>", "<SPECIAL>"};
	input[5] = (t_relation){"<PIPE>", "<PIPE>"};
}

static void	st_validate_to_null(t_relation *input)
{
	input[6] = (t_relation){"<TERMINAL>", "<TERMINAL>"};
	input[7] = (t_relation){"<STRING>", "<FLAG>"};
	input[8] = (t_relation){"<ARGUMENT>", NULL};
	input[9] = (t_relation){"<STRING>", "<STRING>"};
	input[10] = (t_relation){"<SPECIAL>", "<STRING>"};
	input[11] = (t_relation){"<SPECIAL>", "<FLAG>"};
	input[12] = (t_relation){"<SPECIAL>", "<ARGUMENT>"};
	input[13] = (t_relation){"<PIPE>", "<FLAG>"};
	input[14] = (t_relation){"<PIPE>", "<ARGUMENT>"};
	input[15] = (t_relation){"<PIPE>", "<SPECIAL>"};

}

//	*input[] = (t_relation){"<>", "<>"};
