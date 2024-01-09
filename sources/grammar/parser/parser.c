/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:30:37 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 14:30:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	**find_next_command(t_token *tokens);
char	**grid_add_element(char **grid, char *value);

t_cmd_table	*parser(t_pushdown_automaton *parse_bot, t_token *tokens)
{
	t_cmd_table	*output;
	t_token		*temp;
	int	act;
	int	i;

	i = 0;
	output = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
	temp = tokens;
	printf("{ O - o }\t <| parsing process initializing\n");
	while (temp)
	{
		act = automaton_act(parse_bot, &temp);
		if (act == FALSE_INDEX)
		{
			free(output);
			return (NULL);
		}
	}
	output->command = (t_command *)mem_calloc(1, sizeof(t_command));
	output->command->parsed = automaton_find_command(tokens);
	output->command->io[0] = 1;
	output->command->io[1] = 1;
	put_dll(parse_bot->stack->top, 1);
	// restart stack
	return (output);
}

char	**automaton_find_command(t_token *tokens)
{
	char	**output;

	output = (char **)mem_calloc(1, sizeof(char *));
	while (tokens && str_comp(tokens->token_type, "<PIPE>") != 0)
	{
		output = grid_add_element(output, tokens->value);
		tokens = tokens->next;
	}
	return (output);
}

char	**grid_add_element(char **grid, char *value)
{
	char	**output;
	int			lenght;

	lenght = grid_len(grid);
	output = (char **)mem_calloc(lenght + 2, sizeof(char *));
	output[lenght] = value;
	free(grid);
	return (output);
}
