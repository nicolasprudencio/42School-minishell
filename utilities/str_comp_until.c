/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_comp_until.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:42:18 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/26 08:55:40 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	str_comp_until(char *str1, char *str2, int c)
{
	int	i;

	i = -1;
	if (!str1 || !str2)
		return (FALSE);
	while (str1[++i] && str2[i] && str1[i] != c)
		if (str1[i] != str2[i])
			return (FALSE);
	if ((str1[i] == c && str2[i] == '\0') ||
			(str1[i] == c && str2[i] == c) ||
				(str1[i] == c && is_space(str2[i])) ||
					(str1[i] == c && str2[i] == '$') ||
						(str1[i] == c && str2[i] == '\\'))
		return (TRUE);
	return (FALSE);
}