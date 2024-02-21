/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:17:34 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:19:20 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static char	*st_copy_no_quotes(char *line, int hold);
static void	st_expand(t_llist *env, char **content);

int	token_add_string(t_token **tokens, char *line, t_llist *env)
{
	int		hold;
	char	*content;

	hold = -1;
	if (str_is_enclosed(line, '\"') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\"');
	else if (str_is_enclosed(line, '\'') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\'');
	else
		while (line[++hold] && !is_space(line[hold])
			&& line[hold] != '|')
			;
	content = st_copy_no_quotes(line, hold);
	st_expand(env, &content);
	if (!content)
		return (FALSE_INDEX);
	token_push_last(tokens, token_new(content, "<STRING>"));
	free(content);
	return (hold);
}

static void	st_expand(t_llist *env, char **content)
{
	if (str_is_enclosed(*content, '\'') != FALSE_INDEX)
		return ;
	if (str_len_until(*content, '$') != FALSE_INDEX)
		*content = expand_variable(env, *content);
}

static char	*st_copy_no_quotes(char *line, int hold)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str_is_enclosed(line, '\'') != FALSE_INDEX
		|| str_is_enclosed(line, '\"') != FALSE_INDEX)
	{
		hold -= 2;
		output = (char *)mem_calloc(hold + 1, sizeof(char));
		if (!output)
			return (NULL);
		if (line[0] == '\'' || line[0] == '\"')
			i++;
		while (j < hold && line[i] != '\'' && line[i] != '\"')
			output[j++] = line[i++];
		return (output);
	}
	output = (char *)mem_calloc(hold + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (j < hold)
		output[j++] = line[i++];
	return (output);
}
