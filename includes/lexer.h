#ifndef LEXER_H
# define LEXER_H

typedef struct s_token {
	char 	*token_type;
	char	*value;
	// struct s_token	*next;
}				t_token;

t_token	*lex_core(char *line, t_dictionary *dict);
void	lex_token_free(t_token *tokens);

#endif
