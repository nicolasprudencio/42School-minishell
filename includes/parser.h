#ifndef PARSER_H
# define PARSER_H

typedef struct	s_command
{
	char	**parsed;
	int	io[2];
}	t_command;

typedef struct	s_cmd_table
{
	t_command	*command;
	struct s_cmd_table	*next;
}	t_cmd_table;

typedef struct s_prodution
{
	char	*variable;
	char	**output;
}	t_production;

typedef struct	s_dictionary
{
	char	**variables;
	char	**terminals;
	t_production	*production;
	char	*start;
}	t_dictionary;

typedef struct s_relation
{
	char	*input;
	char	*stack_top;
}	t_relation;

typedef struct s_stack
{
	t_dllist	*top;
	t_dllist	*bot;
}	t_stack;

typedef struct	s_pushdown_automaton
{
	int	*states;
	char	**input_alphabet;
	char	**stack_alphabet;
	t_relation	*transition;
	int	starting_state;
	char	initial_symbol;
	int	*accepting_states;
	t_stack	*stack;
}	t_pushdown_automaton;

t_cmd_table	*parser(t_pushdown_automaton *robot, t_token *tokens);

char		automaton_find_command(t_token *tokens);
char	**grid_add_element(char *8grid, char *value);

#endif
