#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_env_lst {
	char		*value;
	struct s_env_lst	*next;
}	t_lst;

t_lst	*new_lst(char **variables);
void		lst_add_back(t_lst	**lst, t_lst *new);
t_lst	*lst_new(char *value);
void		lst_del_one(t_lst *lst);
void		clear_lst(t_lst **lst);

int		exec_cd(char *dir, t_lst **lst);
int		exec_echo(char **str, int flag, int fd);
void	exec_env(t_lst *lst, int fd);
int		exec_export(t_lst *lst, char *var, int fd);
int		exec_unset(t_lst **lst, char *var);
int		get_pwd();


#endif