/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:14 by fpolaris          #+#    #+#             */
/*   Updated: 2023/12/19 10:44:15 by fpolaris         ###   ########.fr       */
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
