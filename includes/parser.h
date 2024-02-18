#ifndef PARSER_H
# define PARSER_H

t_cmd_table	*parser(t_pushdown_automaton *robot, t_token *tokens);

// automaton control
// 	create / destroy
t_pushdown_automaton	*automaton_new(char **env);
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

//	command_table actions
int		cmdt_create(t_pushdown_automaton *parse_bot, 
						t_cmd_table **cmd_table, t_token *token);
void	cmdt_destroy(t_cmd_table **cmd_table);
void	cmd_destroy(t_cmd_table *cmd);

int		cmd_pipe(t_cmd_table **cmd_table);
int		cmd_iredir(t_cmd_table **cmd_table, t_token *token);
int		cmd_oredir(t_cmd_table **cmd_table, t_token *token);
int		cmd_append(t_cmd_table **cmd_table, t_token *token);

int		cmd_create(t_cmd_table **cmd_table, t_token *token);

int		cmd_add(t_cmd_table **cmd, t_token *token, int flag);
void	cmd_last(t_cmd_table **last, t_cmd_table **cmd_table);

void	put_cmdt(t_cmd_table *cmd_table);


// to libfpp
char	**grid_add_element(char **grid, char *value);

#endif
