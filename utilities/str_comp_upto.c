/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_comp_upto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:55:51 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/19 10:44:22 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	str_comp_upto(char *str1, char *str2, char end)
{
	int	i;

	i = -1;
	while (str1[++i] && str1[i] != end)
	{
		if (!str2[i] && str1[i] && str1[i] != end)
			return (-1);
		if (str1[i] != str2[i])
			return (1);
	}
	return (0);
}

