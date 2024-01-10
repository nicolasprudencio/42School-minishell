#ifndef LIBSEAS_H
# define LIBSEAS_H

# define TRUE 1
# define FALSE 0
# define FALSE_INDEX -1

# include "libfpp.h"
# include "grammar.h"
# include "lexer.h"
# include "parser.h"
# include "builtins.h"
# include <readline/readline.h>
# include <readline/history.h>

int	is_terminal(t_dictionary *language, char *line);
int	is_flag(char *line);
int	str_is_enclosed(char *line, int c);
int	str_comp_upto(char *str1, char *str2, char end);

t_stack	*stack_new();
void	stack_push(t_stack *stack, char *content);
void	stack_rpush_tab(t_stack* stack, char **input);
void	stack_pop(t_stack *stack);

char	*get_user(char *path);
char	*get_history_path();
int		get_history();

#endif
