/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:01:00 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/15 18:17:33 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

// static char	*str_dup_len(char *s, int len)
// {
// 	char	*s2;
// 	int		i;

// 	s2 = (char *)mem_calloc(len, sizeof(char)) + 1;
// 	i = -1;
// 	while (++i < len)
// 		s2[i] = s[i];
// 	s2[i] = '\0';
// 	return (s2);
// }

static char	*st_replace_word(char *line, char *var)
{
	int		before_len;
	int		line_len;
	int		var_len;
	char	*output;
	char	*var_value;

	before_len = -1;
	line_len = str_len(line);
	while (line[++before_len] && before_len <= line_len)
		if (line[before_len] == '$' && is_alpha(line[before_len + 1]))
			break ;
	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	var_value = str_copy_upto(str_find_char(var, '=', 1), '\0');
	var_len = str_len_until(var, '=') + 1;
	output = str_join(output, var_value, 2);
	if (!output)
		return (line);
	output = str_join(output, &line[before_len + var_len], 1);
	if (!output)
		return (line);
	free(line);
	return (output);
}

static char	*st_remove_word(char *line, int rest_len)
{
	int		before_len;
	char	*output;

	before_len = str_len(line) - rest_len;
	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	while(line[before_len] && !is_space(line[++before_len]))
		;
	output = str_join(output, &line[before_len], 1);
	if (!output)
		return (line);
	free(line);
	return (output);
}

static char	*st_next_variable(char *line)
{
	char	*str;

	str = str_find_char(line, '$', 0);
	while (str[0] && !is_alpha(str[1]))
		str = str_find_char(&str[1], '$', 0);
	if (str)	
		return (str);
	return (NULL);	
}

char	*expand_variable(t_lst *lst, char *line)
{
	t_lst	*aux;
	char	*str;

	aux = lst;
	str = st_next_variable(line);
	while (aux)
	{
		if (str && str_comp_until(aux->value, &str[1], '='))
		{	
			line = st_replace_word(line, aux->value);
			if (str)
				line = expand_variable(lst, line);
			break ;
		}
		aux = aux->next;
	}
	str = st_next_variable(line);
	printf("%s\n", str);
	if (str[0] && is_alpha(str[1]))
	{
		line = st_remove_word(line, str_len(str));
		line = expand_variable(lst, line);
	}
	return (line);
}