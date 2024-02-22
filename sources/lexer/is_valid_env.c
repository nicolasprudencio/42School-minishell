/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:42:18 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/19 14:21:51 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	is_valid_env(char *env, char *value, int c)
{
	int	i;

	i = 0;
	if (!env || !value)
		return (FALSE);
	while (env[i] && value[i] && env[i] != c)
	{	
		if (env[i] != value[i])
			return (FALSE);
		i++;
	}
	if ((env[i] == c && value[i] == c) || \
		(env[i] == c && value[i] == '$') || \
		(env[i] == c && value[i] == '\\') || \
		(env[i] == c && value[i] == '\"') || \
		(env[i] == c && value[i] == '\'') || \
		(env[i] == c && value[i] == '\0') || \
		(env[i] == c && is_space(value[i])))
		return (TRUE);
	return (FALSE);
}
