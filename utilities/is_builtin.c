/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:26:43 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/17 17:27:28 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	is_builtin(t_dictionary *dict, char *line)
{
	int	i;

	i = -1;
	while (dict->terminals[++i])
	{
		if (!str_comp_upto(line, dict->terminals[i], ' '))
			return (i);
		else if (!str_comp_upto(line, dict->terminals[i], '|'))
			return (i);
	}
	return (FALSE_INDEX);
}