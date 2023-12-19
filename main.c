/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:24 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/12 17:13:22 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_grammar_display(t_dictionary *dictionary);

int	main(void)
{
	char	*rl_output;
	t_dictionary *dictionary;
	t_token	*tokens;

	dictionary = grammar_new();
	while (1)
	{
		rl_output = readline("SEAshell~ ");
		tokens = lexer(rl_output, dictionary);
		put_token(tokens);
		token_free(&tokens);
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			grammar_end(dictionary);
			return (0);
		}
		if (!(str_comp(rl_output, "test")))
			st_grammar_display(dictionary);
		free(rl_output);
	}
	grammar_end(dictionary);
	grid_free(dictionary->terminals);
	free(dictionary);
	return (0);
}

static void	st_grammar_display(t_dictionary *dictionary)
{
	int	i;

	i = -1;
	fp_printf("variables: \n");
	while (dictionary->variables[++i])
		fp_printf("%s\n", dictionary->variables[i]);
	fp_printf("\n");
	fp_printf("terminals: \n");
	i = -1;
	while (dictionary->terminals[++i])
		fp_printf("%s\n", dictionary->terminals[i]);
	fp_printf("\n");
	fp_printf("productions: \n");
	i = -1;
	while ((dictionary->production[++i]).variable)
	{
		int	j = -1;
		fp_printf("%12s ::= ", (dictionary->production[i]).variable);
		if ((dictionary->production[i]).output)
		{
			while ((dictionary->production[i]).output[++j])
				fp_printf("%s", (dictionary->production[i]).output[j]);
		}
		fp_printf("\n");
	}
}
