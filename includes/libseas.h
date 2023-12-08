#ifndef LIBSEAS_H
# define LIBSEAS_H

# include "libfpp.h"
# include "parser.h"
# include "grammar.h"
# include "lexer.h"
# include <readline/readline.h>
# include <readline/history.h>

int	is_terminal(t_dictionary *language, char *compare);
int	is_variable(t_dictionary *language, char *compare);

#endif
