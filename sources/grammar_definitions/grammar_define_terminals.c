/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_define_terminals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:11:40 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:11:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfpp.h"

char	**grammar_define_terminals(void)
{
	char	**terminals;

	terminals = (char **)mem_calloc(8, sizeof(char *));
	terminals[0] = str_dup("echo");
	terminals[1] = str_dup("cd");
	terminals[2] = str_dup("pwd");
	terminals[3] = str_dup("export");
	terminals[4] = str_dup("unset");
	terminals[5] = str_dup("env");
	terminals[6] = str_dup("exit");
	return (terminals);
}

void	grammar_free_terminals(char **terminals)
{
	int	i;

	i = -1;
	if (terminals)
	{
		while (terminals[++i])
			free(terminals[i]);
		free(terminals);
	}
}
