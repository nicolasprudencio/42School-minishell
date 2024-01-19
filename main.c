/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:24 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 15:05:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	main(void)
{
	t_pushdown_automaton *parse_bot;

	parse_bot = automaton_new();
	while (1)
	{
		if (!core(parse_bot, "SEAshell~ ", STDIN_FILENO))
			break ;
	}
	automaton_destroy(parse_bot);
}

/*
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
		add_history(rl_output);
		// lexer
		tokens = lexer(rl_output, dictionary);

		//parser
		commands = parser(parse_bot, tokens);
		put_cmdt(commands);
		automaton_cmdt_destroy(&commands);
		// exec
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			token_free(&tokens);
			break;
		}
		// 	test displays
		else if (!str_comp(rl_output, "parsebot"))
			st_parse_bot_display();
		else if (!str_comp(rl_output, "parsebot -t")
				|| !str_comp(rl_output, "parse_bot --trans"))
			st_parse_bot_display_productions(parse_bot);

		// free temporary data

		token_free(&tokens);
		free(rl_output);
	}
	automaton_destroy(parse_bot);
	grammar_end(dictionary);
	return (0);
}

static void	st_parse_bot_display(void)
{
	printf("\t\t  | HELLO! I'M THE PARSE_BOT!\n");
	printf("   { O - o }\t  | A SIMPLE PUSHDOWN AUTOMATON\n");
	printf("    __| |__\t  | YOU CAN EXPLORE FURTHER\n");
	printf("    / | |  \\\t <| WITH SIMPLE COMMANDS.\n");
	printf("    | | |  |\t  | TO SEE THE FULL LIST OF\n");
	printf("       |\t  | PRODUCTIONS TYPE:\n");
	printf("     O===O\t  |\n");
	printf("\t\t  | parsebot --trans || -t\n");
}

static void	st_parse_bot_display_productions(t_pushdown_automaton *parse_bot)
{
	int	i = -1;

	printf("\t\t\t\t    { O - o }\n");
	for (int j = 0; j < 80; j++)
		printf("_");
	printf("\n\n");
	printf("The starting symbol is: '%s'\n\n", parse_bot->initial_symbol);
	printf("\t\tValid transitions:\n\n");
	while (parse_bot->transition[++i].input)
		printf("input: %-10s\tstack top: %-10s\n\n",
				parse_bot->transition[i].input,
				parse_bot->transition[i].stack_top);
	printf("\t\tBackus-naur form:\n\n");
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
*/
