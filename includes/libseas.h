#ifndef LIBSEAS_H
# define LIBSEAS_H

# define FALSE_INDEX -1
# define FD_HEREDOC -3

# define STD_ERROR "SEAshell: Syntax error near unexpected token:"

# include "libfpp.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include "structs.h"
# include "states.h"
# include "grammar.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"

int		core(t_pushdown_automaton *parse_bot, char * prompt, int fd);
void	heredoc(t_llist *env_lst, t_token *tokens, t_cmd_table *cmd);
void	handle_signals(void);
void	handle_exec_signals();
char	*expand_variable(t_llist *lst, char *line);
int		*get_status();

// UTILITIES

int		is_builtin(t_dictionary *language, char *line);
int		is_flag(char *line);
int		is_terminal(t_llist *env_lst, char *line);
int		is_terminal2(t_llist *env_lst, char **line);
int		char_exists(char *s, int c);
int		str_len_until(char *s, int c);
int		str_is_enclosed(char *line, int c);
char	*ft_itoa(int n);

#endif
