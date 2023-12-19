/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:25 by fpolaris          #+#    #+#             */
/*   Updated: 2023/12/19 10:44:26 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	str_is_enclosed(char *line, int c)
{
	int	i;

	i = -1;
	if (line[++i] == c)
	{
		while (line[++i] && line[i] != c)
			;
		if (!line[i++])
			return (-2);
		return (i);
	}
	return (FALSE_INDEX);
}
