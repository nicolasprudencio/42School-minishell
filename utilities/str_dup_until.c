/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:46:32 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/16 18:59:08 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	*str_dup_until(char *s, int c)
{
	char	*s2;
	int		len;
	int		i;

	len = str_len_until(s, ' ') + 1;
	s2 = (char *)mem_calloc(len, sizeof(char));
	i = -1;
	while (s[++i] != c)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);	
}