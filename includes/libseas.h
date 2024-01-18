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

int	char_exists(char *s, int c);
int	is_builtin(t_dictionary *dict, char *line);
int	is_terminal(t_lst *env_lst, char *line);
int	is_flag(char *line);
int	str_is_enclosed(char *line, int c);
int	str_comp_upto(char *str1, char *str2, char end);
int str_comp_until(char *str1, char *str2, int c);
int	str_len_until(char	*s, int c);
char	*env_expand_variables(char	*line, t_lst *lst);

t_stack	*stack_new();
void	stack_push(t_stack *stack, char *content);
void	stack_rpush_tab(t_stack* stack, char **input);
void	stack_pop(t_stack *stack);

void	heredoc(t_lst *lst, char *eof, int fd);

#endif
