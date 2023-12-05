#ifndef LEXER_H
# define LEXER_H

typedef struct s_token {
	char 	*token_type;
	char	*value;
	struct s_token	*next;
	// struct s_token	*prev;
}				t_token;

t_token	*lex_core(char *line, t_dictionary *dict);
int		is_terminal(char *line, t_dictionary *dict, int index);
void	lex_token_free(t_token **tokens);
void	tokens_print_list(t_token *tokens);
void	token_push_last(t_token **tokens, t_token *new);
t_token *token_push(t_dictionary *dict, int g_index);

#endif
