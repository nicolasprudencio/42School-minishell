#ifndef LEXER_H
# define LEXER_H

typedef struct s_token {
	char 	*token_type;
	char	*value;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

t_token	*lexer(char *line, t_dictionary *dict);

t_token	*token_new(char *value, char *type);
void	token_free(t_token **tokens);

void	token_push_last(t_token **tokens, t_token *new);

void	put_token(t_token *tokens);

#endif
