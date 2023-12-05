/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/12/04 21:23:55 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int g_index;

int	is_terminal(char *line, t_dictionary *dict, int i)
{	
	g_index = -1;
	while(dict->terminals[++g_index])
			if (str_ncmp(dict->terminals[g_index], &line[i], str_len(dict->terminals[g_index])) == 0)
				return (TRUE);
	return (FALSE);
}

t_token *lex_core(char *line, t_dictionary *dict)
{	
	int		i;
	t_token	*token;
	
	i = 0;
	while (is_space(line[i]))
	{	
		i++;
		if (line[i] == '\0')
			return (NULL);
	}
	if (is_terminal(&line[i], dict, i))
	{
		token = (t_token *)mem_calloc(1, sizeof(t_token));
		if (!token)
			return (NULL);
		token->token_type = str_dup("terminal");
		token->value = str_dup(dict->terminals[g_index]);
		fp_printf("%s | ", token->token_type);
		fp_printf("%s\n", token->value);
		return (token);
	}
	return (NULL);
}

void	lex_token_free(t_token *tokens)
{
	if (tokens)
	{
		free(tokens->value);
		free(tokens);
	}
}
