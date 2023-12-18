/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_what_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:55:51 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/14 18:25:08 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"
/*
int	exists_token(char *line, char **list)
{	
	g_index = -1;
	while(list[++g_index])
		if (str_comp_upto(line, list[g_index],'|') == 0
			|| str_comp_upto(line, list[g_index], ' ') == 0)
			return (g_index);	
	return (FALSE_INDEX);
}
*/
static int	str_comp_upto(char *str1, char *str2, char end)
{
	int	i;

	i = -1;
	while (str1[++i] && str1[i] != end)
	{
		if (!str2[i] && str1[i] && str1[i] != end)
			return (-1);
		if (str1[i] != str2[i])
			return (1);
	}
	return (0);
}

int	is_terminal(t_dictionary *dict, char *line)
{
	int	i;

	i = -1;
	while (dict->terminals[++i])
	{
		if (!str_comp_upto(line, dict->terminals[i], ' '))
			return (i);
		else if (!str_comp_upto(line, dict->terminals[i], '|'))
			return (i);
	}
	return (FALSE_INDEX);
}

int	is_flag(char *line)
{
	if (line[0] == '-' && is_alpha(line[1]))
			return (1);
	return (FALSE_INDEX);
}

// int	is_flag(char *flag, t_dictionary *dict)
// {
// 	g_index = -1;
// 	while (dict->variables[++g_index])
// 		if (str_comp_upto(flag, dict->variables[g_index], '|') == 0
// 		|| str_comp_upto(flag, dict->variables[g_index], ' ') == 0)
// 			return (g_index);
// 	return (FALSE_INDEX);
// }

// int	is_special(char *line, t_dictionary *dict)
// {
// 	g_index = -1;
// 	while (dict->specials[++g_index])
// 		if (str_comp_upto(line, dict->specials[g_index]))
// }
