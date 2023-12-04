#ifndef PARSER_H
# define PARSER_H

typedef struct	s_command
{
	char	**parsed;
	int	input;
	int	output;
}	t_command;

typedef struct	s_cmd_tabble
{
	t_command	*commands;
}	t_cmd_tabble;

typedef struct	s_relation
{
	char	*input;
	char	**outputs;
}	t_relation;

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
	int	state;
	char	*input;
	char	*stack_top;
	void	(*action) (t_dictionary *lang, t_stack *stack);
}	t_relation;

typedef struct	s_pushdown_automaton
{
	int	*states;
	char	**input_alphabet;
	char	**stack_alphabet;
	t_relation	*transition_relation;
	int	starting_state;
	char	initial_symbol;
	int	*accepting_states;
}	t_pushdown_automaton;



#endif
