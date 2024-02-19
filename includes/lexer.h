#ifndef LEXER_H
# define LEXER_H

t_token	*lexer(char *line, t_pushdown_automaton *parse_bot);

t_token	*token_new(char *value, char *type);
void	token_free(t_token **tokens);
int		token_last_is_pipe(t_token **tokens);

int		token_add_flag(t_token **tokens, char *line);
int		token_add_special(t_token **tokens, char *line);
int		token_add_string(t_token **tokens, char *line, t_llist *env);
int		token_add_terminal(t_dictionary *dict, t_token **tokens, char *line);

void	token_push_last(t_token **tokens, t_token *new);

char	*expand_variable(t_llist *env_list, char *line);
int		is_valid_env(char *env, char *value, int c);

void	put_token(t_token *tokens);


#endif
