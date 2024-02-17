#ifndef BUILTINS_H
# define BUILTINS_H

# include "libseas.h"

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot);
int	exec_open_process(t_cmd_table **cmd, int current_cmd,
				t_pushdown_automaton *parse_bot);

// builtins

int	exec_cd(char *dir, t_llist **lst);
int	exec_echo(char **str, int fd);
void	exec_env(t_llist *lst, int fd);
int	exec_export(t_llist *lst, char *var, int fd);
int	exec_unset(t_llist **lst, char *var);
int	get_pwd(void);

#endif
