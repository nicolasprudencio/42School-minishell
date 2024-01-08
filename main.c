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

static void	st_parse_bot_display_productions(t_pushdown_automaton *parse_bot);
static void	st_parse_bot_display(void);

int	main(void)
{
	char	*rl_output;
	t_dictionary *dictionary;
	t_token	*tokens;
	t_cmd_table	*commands;
	t_pushdown_automaton	*parse_bot;

	dictionary = grammar_new();
	parse_bot = automaton_new(dictionary);
	while (1)
	{
		rl_output = readline("SEAshell~ ");
		// lexer
		tokens = lexer(rl_output, dictionary);

		//parser
		commands = parser(parse_bot, tokens);
		token_free(&tokens);

		// exec
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			grammar_end(dictionary);
			return (0);
		}
		// 	test displays
		else if (!str_comp(rl_output, "parsebot"))
			st_parse_bot_display();
		else if (!str_comp(rl_output, "parsebot -t")
				|| !str_comp(rl_output, "parse_bot --trans"))
			st_parse_bot_display_productions(parse_bot);
		free(rl_output);
	}
	grammar_end(dictionary);
	grid_free(dictionary->terminals);
	free(dictionary);
	return (0);
}

static void	st_parse_bot_display(void)
{
	printf("\t\t\t\t | HELLO! I'M THE PARSE_BOT!\n");
	printf("\t\t   { O - o }\t | A SIMPLE PUSHDOWN AUTOMATON\n");
	printf("\t\t    __| |__\t | YOU CAN EXPLORE FURTHER\n");
	printf("\t\t    / | |  \\\t<  WITH SIMPLE COMMANDS.\n");
	printf("\t\t    | | |  |\t | TO SEE THE FULL LIST OF\n");
	printf("\t\t       |\t | PRODUCTIONS TYPE:\n");
	printf("\t\t     O===O\t |\n");
	printf("\t\t\t\t | parsebot --trans || -t\n");
}

static void	st_parse_bot_display_productions(t_pushdown_automaton *parse_bot)
{
	int	i = -1;

	printf("\t\t\t\t    { O - o }\n");
	for (int j = 0; j < 80; j++)
		printf("_");
	printf("\n\n");
	printf("The starting symbol is: '%s'\n\n", parse_bot->initial_symbol);
	printf("\t\t\t\tValid transitions:\n\n");
	while (parse_bot->transition[++i].input)
		printf("input: %-10s\t\tstack top: %-10s\n\n",
				parse_bot->transition[i].input,
				parse_bot->transition[i].stack_top);
	printf("\t\t\t\tBackus-naur form:\n\n");
	i = -1;
	while (parse_bot->language->production[++i].variable)
	{
		printf("%-10s\t::=", parse_bot->language->production[i].variable);
		if (!parse_bot->language->production[i].output)
			printf("\t<\"NULL\">");
		else
		{
			for (int j = 0; parse_bot->language->production[i].output[j]; j++)
			{
					printf("\t%-10s",
					parse_bot->language->production[i].output[j]);
			}
		}
		printf("\n");
	}
	for (int j = 0; j < 80; j++)
		printf("_");
	printf("\n");
}
