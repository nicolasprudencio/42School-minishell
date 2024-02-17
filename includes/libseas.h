#ifndef LIBSEAS_H
# define LIBSEAS_H

# define FALSE_INDEX -1
# define FD_HEREDOC -3

# define STD_ERROR "SEAshell: Syntax error near unexpected token:"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libfpp.h"
# include "structs.h"
# include "states.h"
# include "grammar.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"

int	core(t_pushdown_automaton *parse_bot, char * prompt, int fd);
void	heredoc(t_llist *env_lst, char *eof, int fd);
char	*expand_variable(t_llist *lst, char *line);
int	is_builtin(t_dictionary *language, char *line);
int	is_flag(char *line);
int	is_terminal(t_llist *env_lst, char *line);
int	is_terminal2(t_llist *env_lst, char **line);
int	char_exists(char *s, int c);
int	str_comp_until(char *str1, char *str2, int c);
int	str_len_until(char *s, int c);
int	str_is_enclosed(char *line, int c);
int	str_comp_upto(char *str1, char *str2, char end);

#endif
