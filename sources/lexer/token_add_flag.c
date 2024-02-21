/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:17:22 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:17:23 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	token_add_flag(t_token **tokens, char *line)
{
	int		hold;
	int		i;
	char	*content;

	hold = -1;
	if (line[++hold] == '-')
	{
		while (is_alpha(line[++hold]) || line[hold] == '-')
			;
		content = (char *)mem_calloc(hold + 1, sizeof(char));
		i = -1;
		while (++i < hold)
			content[i] = line[i];
		token_push_last(tokens, token_new(content, "<FLAG>"));
		free(content);
		return (hold);
	}
	return (FALSE_INDEX);
}
