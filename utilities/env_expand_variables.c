/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:05:24 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/18 17:03:19 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	*check_variable(char *line)
{
	int		i;
	char	*var;

	i = -1;
	var = NULL;
	while (line[++i])
	{
		if (line[i] == '$')
		{	
			if (str_len_until(&line[i + 1], ' ') != FALSE_INDEX)
				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], ' '));
			else if (str_len_until(&line[i + 1], '\n') != FALSE_INDEX)
				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], '\\'));	
			else
				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], '\0'));
		}
	}
	return (var);
}

char	*env_expand_variables(char *line, t_lst *lst)
{
	t_lst	*aux;
	char	*var;
	int		i;

	aux = lst;
	var = NULL;
	i = -1;
	var = check_variable(line);
	if (var)
	{
		while (aux)
		{
			if (str_comp_until(var, aux->value, '\\') || str_comp_until(aux->value, var, '='))
			{	
				free(var);
				return (str_find_char(aux->value, '=', 1));
			}
			aux = aux->next;
		}
	}
	return (NULL);
}