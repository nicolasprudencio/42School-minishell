/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:30:30 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:30:30 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	*automaton_states(void)
{
	int	*output;

	output = (int *)mem_calloc(1, sizeof(int));
	if (!output)
		return (NULL);
	output[0] = 1;
	return (output);
}
