#include "libseas.h"

char	**find_next_command(t_token *tokens);
char	**grid_add_element(char **grid, char *value);

t_cmd_table	*parser(t_pushdown_automaton *robot, t_token *tokens)
{
	t_cmd_table	*output;
	t_token		*temp;
	int	act;
	int	i;

	i = 0;
	output = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
	temp = tokens;
	while (temp)
	{
		act = automaton_act(robot, temp);
		if (act == FALSE_INDEX)
		{
			free(output);
			return (NULL);
		}
		else if (act < 3)
			temp = temp->next;
	}
	output->command->parsed = automaton_find_command(tokens);
	output->command->io[0] = 1;
	output->command->io[1] = 1;
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

	output = (char **)mem_calloc(sizeof(grid) + 1, sizeof(char *));
	output[sizeof(grid)] = value;
	free(grid);
	return (output);
}
