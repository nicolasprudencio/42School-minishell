/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:08:05 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/20 17:27:07 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	str_len_until(char	*s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (FALSE_INDEX);
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	if (c == '\0' && s[i] == '\0')
		return (i);
	return (FALSE_INDEX);
}