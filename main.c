/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:24 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/07 19:34:10 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	main(void)
{
	char	*rl_output;
	t_dictionary *dictionary;
	t_token	*tokens;

	dictionary = mem_calloc(1, sizeof(t_dictionary));
	dictionary->terminals = grammar_define_terminals();
	dictionary->variables = grammar_define_variables();
	fp_printf("flags = %s\n", dictionary->variables[0]);
	while (1)
	{
		rl_output = readline("SEAshell~ ");
		tokens = lex_core(rl_output, dictionary);
		lex_token_free(&tokens);
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			grid_free(dictionary->terminals);
			free(dictionary);
			return (0);
		}
		free(rl_output);
	}
	grid_free(dictionary->terminals);
	free(dictionary);
	return (0);
}
