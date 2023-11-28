#ifndef PARSER_H
# define PARSER_H

typedef struct	s_command
{
	char	**parsed;
	int	input;
	int	output;
}

typedef struct	s_cmd_tabble
{
	t_command	*commands;
}	t_cmd_tabble;

typedef struct	s_relation
{
	char	*input;
	char	**outputs;
}	t_relation;

typedef struct	s_context_free_grammar
{
	char	**variable;
	char	**terminal;
	t_relation	*production;
	char	*start;
}	t_context_free_grammar;

typedef struct	s_pushdown_automaton
{
	int	*states;
	char	**input_alphabet;
	char	**stack_alphabet;
	char	**transition_relation;
	int	starting_state;
	char	initial_symbol;
	chr	**accepting_states;
}	t_pushdown_automaton;

#endif
