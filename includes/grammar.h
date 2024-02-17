#ifndef GRAMMAR_H
# define GRAMMAR_H

t_dictionary	*grammar_new();
void	grammar_end(t_dictionary *seas_script);

char	**grammar_define_terminals();
void	grammar_free_terminals(char **terminals);

t_production	*grammar_define_productions();
void	grammar_free_productions(t_production *product);

char	**grammar_define_variables();
void	grammar_free_variables(char **variables);

#endif
