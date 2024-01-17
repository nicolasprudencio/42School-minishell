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

	output = (t_relation *)mem_calloc(18, sizeof(t_relation));
	if (!output)
		return (NULL);
	output[0] = (t_relation){"<TERMINAL>", "<COMMAND>"};
	output[1] = (t_relation){"<STRING>", "<COMMAND>"};
	output[2] = (t_relation){"<SPECIAL>", "<COMMAND>"};
	output[7] = (t_relation){"<SPECIAL>", "<STRING>"};
	st_recursive_cases(output);
	st_validate_to_null(output);
	return (output);
}

static void	st_recursive_cases(t_relation *input)
{
	input[3] = (t_relation){"<FLAG>", "<FLAG>"};
	input[4] = (t_relation){"<STRING>", "<ARGUMENT>"};
	input[5] = (t_relation){"<SPECIAL>", "<SPECIAL>"};
	input[6] = (t_relation){"<PIPE>", "<PIPE>"};
}


static void	st_validate_to_null(t_relation *input)
{
	input[8] = (t_relation){"<TERMINAL>", "<TERMINAL>"};
	input[9] = (t_relation){"<STRING>", "<FLAG>"};
	input[10] = (t_relation){"<ARGUMENT>", NULL};
	input[11] = (t_relation){"<STRING>", "<STRING>"};
	input[12] = (t_relation){"<SPECIAL>", "<FLAG>"};
	input[13] = (t_relation){"<SPECIAL>", "<ARGUMENT>"};
	input[14] = (t_relation){"<PIPE>", "<FLAG>"};
	input[15] = (t_relation){"<PIPE>", "<ARGUMENT>"};
	input[16] = (t_relation){"<PIPE>", "<SPECIAL>"};

}

//	*input[] = (t_relation){"<>", "<>"};
