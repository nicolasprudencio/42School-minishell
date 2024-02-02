/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:25 by fpolaris          #+#    #+#             */
/*   Updated: 2024/01/26 07:53:14 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	str_is_enclosed(char *line, int c)
{
	char	*qline;
	int		i;

	i = 0;
	if (line[i] == c)
	{
		while (line[i] && line[i] != c)
			i++;
		if (!line[i++])
			return (-2);
		if (c == '\"')
			while (1)
			{
				qline = readline("dquote> ");
				free(qline);
			}
		else if (c == '\'')
			while (1)
			{
				qline = readline("quote>");
				free(qline);
			}
		return (i);
	}
	return (FALSE_INDEX);
}
