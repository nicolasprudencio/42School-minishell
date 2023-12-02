/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/12/02 17:31:37 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"


t_token *lexer(char *line, t_dictionary *dict)
{	
	int		i;
	int		j;
	t_token	*token;
	
	i = 0;
	while (is_space(line[i]))
	{	
		i++;
		if (line[i] == '\0')
			return (NULL);
	}
	if (is_alpha(line[i]))
	{
		j = -1;
		while(dict->terminals[++j])
			if (str_ncmp(dict->terminals[j], &line[i], str_len(dict->terminals[j])) == 0)
			{
				token = mem_calloc(1, sizeof(t_token));
				token->token_type = "terminal";
				token->value = str_dup(dict->terminals[j]);
				fp_printf("%s\n", token->token_type);
				fp_printf("%s\n", token->value);
				return (token);
			}
		i++;
	}
	return (NULL);
}