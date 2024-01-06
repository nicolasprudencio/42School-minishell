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
	char	*initial_symbol;
	int	*accepting_states;
	t_stack	*stack;
	t_dictionary	*language;
}	t_pushdown_automaton;

t_cmd_table	*parser(t_pushdown_automaton *robot, t_token *tokens);

// automaton control

t_pushdown_automaton	*automaton_new(t_dictionary *language);
char		**automaton_find_command(t_token *tokens);
int		automaton_act(t_pushdown_automaton *robot, t_token *input);
int		automaton_find_transition(t_pushdown_automaton *robot,
			char *token_type, char *stack_top);
int		*automaton_astates(int *states);
int		*automaton_states(void);
t_relation	*automaton_transition_relation(void);

char	**grid_add_element(char **grid, char *value);

#endif
