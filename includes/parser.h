#ifndef PARSER_H
# define PARSER_H

typedef struct	s_command
{
	char	**parsed;
	long int	io[2];
}	t_command;

typedef struct	s_cmd_table
{
	t_command	*command;
	struct s_cmd_table	*next;
	struct s_cmd_table	*prev;
}	t_cmd_table;

typedef struct s_relation
{
	char	*input;
	char	*stack_top;
}	t_relation;

typedef struct	s_pushdown_automaton
{
	int	current_state;
	t_relation	*transition;
	int	starting_state;
	char	*initial_symbol;
	int	*accepting_states;
	t_stack	*stack;
	t_dictionary	*language;
}	t_pushdown_automaton;

t_cmd_table	*parser(t_pushdown_automaton *robot, t_token *tokens);

// automaton control
// 	create / destroy
t_pushdown_automaton	*automaton_new(t_dictionary *language);
void	automaton_destroy(t_pushdown_automaton *robot);

int		*automaton_astates(void);
t_relation	*automaton_transition_relation(void);

//	actions
int		automaton_act(t_pushdown_automaton *robot,
		t_token **input);
char		**automaton_find_command(t_token *tokens);
int		automaton_find_transition(t_pushdown_automaton *robot,
			t_token *token, char *stack_top);
int		automaton_restart_stack(t_pushdown_automaton *parse_bot);
void		automaton_find_state(t_pushdown_automaton *parse_bot,
			t_token **input);

//	state actions
int		automaton_cmdt_create(t_pushdown_automaton *parse_bot,
			t_cmd_table **cmd_table, t_token *token);
void		automaton_cmdt_destroy(t_cmd_table **cmd_table);

int		automaton_cmd_pipe(t_cmd_table **cmd_table);
int		automaton_cmd_iredir(t_cmd_table **cmd_table, t_token *token);
int		automaton_cmd_oredir(t_cmd_table **cmd_table, t_token *token);

int		automaton_cmd_create(t_cmd_table **cmd_table, t_token *token);

int		automaton_cmd_add(t_cmd_table **cmd, t_token *token, int flag);
void		automaton_cmd_last(t_cmd_table **last, t_cmd_table **cmd_table);

void		put_cmdt(t_cmd_table *cmd_table);


// to libfpp
char	**grid_add_element(char **grid, char *value);

#endif
