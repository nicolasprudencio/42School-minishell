#ifndef BUILTINS_H
# define BUILTINS_H

# include "libseas.h"

int		exec(t_cmd_table **cmd_table,
		t_pushdown_automaton *parse_bot);

int		exec_cd(char *dir, t_lst **lst);
int		exec_echo(char **str, int flag, int fd);
void	exec_env(t_lst *lst, int fd);
int		exec_export(t_lst *lst, char *var, int fd);
int		exec_unset(t_lst **lst, char *var);
int		get_pwd();

#endif
