/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libseas.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:44:48 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/22 04:49:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSEAS_H
# define LIBSEAS_H

# define FALSE_INDEX -1

# define STD_ERROR "SEAshell: Syntax error near unexpected token:"
# define HERE_ERROR "SEAshell: warning: here-document at line %i delimited \
by end-of-file (wanted `%s')\n"

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

int		core(t_pushdown_automaton *parse_bot, char *prompt, int fd);
void	heredoc(t_llist *env_lst, t_token *tokens, t_cmd_table *cmd);
void	run_heredoc(t_llist **doc_lst, t_llist *env, char *eof);
void	handle_signals(void);
void	handle_no_signals(void);
void	handle_exec_signals(void);
void	handle_heredoc_signals(void);
char	*expand_variable(t_llist *lst, char *line);
int		get_status(int new_status);
int		get_pipe(int fd);

// UTILITIES

int		is_builtin(t_dictionary *language, char *line);
int		is_flag(char *line);
int		is_terminal(t_llist *env_lst, char *line);
int		is_terminal2(t_llist *env_lst, char **line);
int		char_exists(char *s, int c);
int		str_len_until(char *s, int c);
int		str_is_enclosed(char *line, int c);
char	*ft_itoa(int n);
char	*var_exists(t_llist *lst, char *var);

#endif
