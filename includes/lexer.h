#ifndef LEXER_H
# define LEXER_H

extern int g_index;

typedef struct s_token {
	char 	*token_type;
	char	*value;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

t_token	*lex_core(char *line, t_dictionary *dict);
t_token	*token_new(char *value, char *type);
int		is_terminal(t_dictionary *dict, char *line);
int		is_flag(char *flag);
void	lex_token_free(t_token **tokens);
void	tokens_print_list(t_token *tokens);
void	token_push_last(t_token **tokens, t_token *new);
void	put_token(t_token *tokens);

#endif
