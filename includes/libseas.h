#ifndef LIBSEAS_H
# define LIBSEAS_H

# define FALSE_INDEX -1

# include "libfpp.h"

# include "states.h"
# include "grammar.h"
# include "lexer.h"
# include "parser.h"

# include <readline/readline.h>
# include <readline/history.h>

int	is_terminal(t_dictionary *language, char *line);
int	is_flag(char *line);

int	str_is_enclosed(char *line, int c);
int	str_comp_upto(char *str1, char *str2, char end);

#endif
