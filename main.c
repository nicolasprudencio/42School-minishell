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
	t_cmd_table	*commands;
	t_pushdown_automaton	*robot;

	dictionary = grammar_new();
	robot = automaton_new(dictionary);
	while (1)
	{
		rl_output = readline("SEAshell~ ");
		// lexer
		tokens = lexer(rl_output, dictionary);
		put_token(tokens);

		//parser
		commands = parser(robot, tokens);
		token_free(&tokens);

		// exec
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			grammar_end(dictionary);
			return (0);
		}
		// 	test displays
		if (!(str_comp(rl_output, "test")))
			st_grammar_display(dictionary);
		if (!str_comp(rl_output, "parse_bot"))
			st_robot_display(robot);
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

static void st_robot_display(t_pushdown_automaton *robot)
{
	
}
