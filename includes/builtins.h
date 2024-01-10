#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_env_lst {
	char		*value;
	struct s_env_lst	*next;
}	t_env_lst;

t_env_lst	*new_lst(char **variables);
void		lst_add_back(t_env_lst	**lst, t_env_lst *new);
t_env_lst	*lst_new(char *value);

int		exec_echo(int fd, char *str, int flag);
void	exec_env(t_env_lst *lst);
int		get_pwd();

#endif