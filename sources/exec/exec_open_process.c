#include "libseas.h"

static int	st_child_process(t_cmd_table *cmd_table, int current_cmd,
		t_pushdown_automaton * parse_bot);
static void	st_close_all_fds(t_cmd_table *cmd, int current_cmd);
static void	st_dup(t_cmd_table *cmd);

int	exec_open_process(t_cmd_table **cmd, int current_cmd,
		t_pushdown_automaton *parse_bot)
{
	int		status;
	pid_t		pid;

	pid = fork();
	status = 0;
	if (pid < 0)
		return (FALSE);
	if (pid == 0)
		st_child_process(*cmd, current_cmd, parse_bot);
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

static void	st_close_all_fds(t_cmd_table *cmd, int current_cmd)
{
	int		i;
	t_cmd_table	*aux;

	i = 0;
	aux = cmd;
	while (aux)
	{
		if (i++ != current_cmd)
		{
			if (aux->command->io[STDIN_FILENO] != STDIN_FILENO
					&& aux->command->io[STDIN_FILENO] != -1)
			close(aux->command->io[STDIN_FILENO]);
			if (aux->command->io[STDOUT_FILENO] != STDOUT_FILENO
					&& aux->command->io[STDOUT_FILENO] != -1)
			close(aux->command->io[STDOUT_FILENO]);
		}
		aux = aux->next;
	}
}

static int	st_child_process(t_cmd_table *cmd_table, int current_cmd,
					t_pushdown_automaton *parse_bot)
{
	t_cmd_table *aux;
	char	**command;
//	char	**env;
	int		i;
	
	i = -1;
	aux = cmd_table;
	while (aux && ++i != current_cmd)
		aux = aux->next;
	command = aux->command->parsed;
	if (is_terminal2(parse_bot->env_list, &command[0]))
	{
		st_dup(aux);
		st_close_all_fds(cmd_table, current_cmd);
//		env = ll_to_tab(parse_bot->env_list);
		execve(command[0], command, NULL);
//		free(env);
	}
	automaton_destroy(parse_bot);
	automaton_cmdt_destroy(&cmd_table);
	exit(1);
}

static void	st_dup(t_cmd_table *cmd)
{
	int		io[2];

	io[STDIN_FILENO] = cmd->command->io[STDIN_FILENO];
	io[STDOUT_FILENO] = cmd->command->io[STDOUT_FILENO];
	dup2(io[STDIN_FILENO], STDIN_FILENO);
	dup2(io[STDOUT_FILENO], STDOUT_FILENO);
}
