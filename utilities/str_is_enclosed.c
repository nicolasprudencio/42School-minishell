/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:25 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/16 18:01:05 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	str_is_enclosed(char *line, int c)
{
	int		i;

	i = 0;
	if (line[i] == c)
	{
		while (line[++i] && line[i] != c)
			;
		if (!line[i])
			return (FALSE_INDEX);
		if (!line[++i])
			return (i);
	}
	return (FALSE_INDEX);
}
