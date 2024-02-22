/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:01:00 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/22 17:19:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"
#include <stdlib.h>

static char	*st_replace_status(char *line, char *var, int before_len)
{
	int		var_len;
	char	*output;
	char	*var_value;

	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	var_value = str_copy_upto(var, '\0');
	var_len = str_len(var) + 1;
	output = str_join(output, var_value, 2);
	if (!output)
		return (line);
	output = str_join(output, &line[before_len + var_len], 1);
	if (!output)
		return (line);
	free(line);
	return (output);
}

static char	*st_replace_word(char *line, char *var, int before_len)
{
	int		var_len;
	char	*output;
	char	*var_value;

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
	line = NULL;
	return (output);
}

static int	st_var_size(char *line)
{
	int	i;

	i = 0;
	while (line[++i] && !is_space(line[i]) && line[i] != '$')
		;
	return (i);	
}

static char	*st_remove_word(char *line, int rest_len)
{
	int		before_len;
	char	*output;
	int		after_var;

	before_len = str_len(line) - rest_len;
	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	after_var = st_var_size(&line[before_len]) + before_len;
	if (before_len == 0 || after_var == (int)str_len(line))
	{
		free(line);
		line = NULL;
		return(output);
	}
	output = str_join(output, &line[after_var], 1);
	if (!output)
		return (line);
	free(line);
	line = NULL;
	return (output);
}

static char	*st_check_var(char *line, char *var, int i)
{
	if (var)
	{
		line = st_replace_word(line, var, i);
		while (line[i] && !is_space(line[i]) && line[i] != '$')
			i++;
	}
	else
		line = st_remove_word(line, str_len(&line[i]));
	return (line);
}

char	*expand_variable(t_llist *lst, char *line)
{
	char	*var;
	int		i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '$' && is_alpha(line[i + 1])) \
		|| (line[i] == '$' && line[i + 1] == '_'))
		{
			var = var_exists(lst, &line[i]);
			line = st_check_var(line, var, i);
		}
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line = st_replace_status(line, ft_itoa(get_status(-1)), i);
			while (line[i] && !is_space(line[i]) && line[i] != '$')
				i++;
		}
		else
			i++;
	}
	return (line);
}
