#include "libseas.h"

static int	st_child_process(t_cmd_table *cmd_table, int current_cmd,
		t_pushdown_automaton * parse_bot);
static void	st_close_all_fds(t_cmd_table *cmd, int current_cmd);
static void	st_dup(t_cmd_table *cmd, int current_cmd);

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
		if (i > current_cmd)
		{
			printf("closing {%i, %i}\n",
					aux->command->io[STDIN_FILENO],
					aux->command->io[STDOUT_FILENO]);
			if (aux->command->io[STDIN_FILENO] != STDIN_FILENO)
					close(aux->command->io[STDIN_FILENO]);
			if (aux->command->io[STDOUT_FILENO] != STDOUT_FILENO)
					close(aux->command->io[STDOUT_FILENO]);
			i++;
		}
		aux = aux->next;
	}
}

static int	st_child_process(t_cmd_table *cmd_table, int current_cmd,
					t_pushdown_automaton *parse_bot)
{
	char	**command;
//	char	**env;

	command = cmd_table->command->parsed;
	printf("current command %i\n", current_cmd);
	if (is_terminal2(parse_bot->env_list, &command[0]))
	{
		st_dup(cmd_table, current_cmd);
		st_close_all_fds(cmd_table, current_cmd);
//		env = ll_to_tab(parse_bot->env_list);
		printf("executing command %s\n", command[0]);
		execve(command[0], command, NULL);
//		free(env);
	}
	automaton_destroy(parse_bot);
	automaton_cmdt_destroy(&cmd_table);
	exit(1);
}

static void	st_dup(t_cmd_table *cmd, int current_cmd)
{
	int		io[2];
	int		i;
	t_cmd_table	*aux;

	aux = cmd;
	i = -1;
	while (aux && ++i != current_cmd)
		aux = aux->next;
	io[STDIN_FILENO] = aux->command->io[STDIN_FILENO];
	io[STDOUT_FILENO] = aux->command->io[STDOUT_FILENO];
	printf("dupping io {0, 1} > {%i, %i}\n", io[STDIN_FILENO], 
			io[STDOUT_FILENO]);
	dup2(io[STDIN_FILENO], STDIN_FILENO);
	dup2(io[STDOUT_FILENO], STDOUT_FILENO);
}
