/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_astates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:29:40 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:40 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	*automaton_astates(int *states)
{
	int	*output;

	output = (int *)mem_calloc(1, sizeof(int));
	if (!output)
		return (NULL);
	output[0] = states[0];
	return (output);
}
