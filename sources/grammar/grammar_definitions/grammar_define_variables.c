/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_define_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:48:54 by nprudenc          #+#    #+#             */
/*   Updated: 2023/11/29 18:49:15 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	**grammar_define_variables()
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
