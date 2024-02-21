/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_define_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:13:31 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:13:33 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	**grammar_define_variables(void)
{
	char	**output;
	char	*temp;

	temp = str_dup("<COMMAND> <ARGUMENT> <FLAG> <TERMINAL> <STRING>");
	output = str_split(temp, ' ');
	free(temp);
	return (output);
}

void	grammar_free_variables(char **variables)
{
	int	i;

	i = -1;
	if (variables)
	{
		while (variables[++i])
			free(variables[i]);
		free(variables);
	}
}
