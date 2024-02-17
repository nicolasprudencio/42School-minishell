#include "libseas.h"

static int	st_child_process(t_cmd_table *cmd_table, 
		t_pushdown_automaton * parse_bot);
static void	st_close_all_fds(t_cmd_table **cmd, int current_cmd);

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
	{
		st_close_all_fds(cmd, current_cmd);
		st_child_process(*cmd, parse_bot);
	}
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

static void	st_close_all_fds(t_cmd_table **cmd, int current_cmd)
{
	int		i;
	t_cmd_table	*aux;

	i = -1;
	aux = (*cmd);
	printf("current command %i\n", current_cmd);
	while (++i < current_cmd)
	{
		printf("closing before {%li, %li}\n", aux->command->io[STDIN_FILENO],
				aux->command->io[STDOUT_FILENO]);
		close(aux->command->io[STDIN_FILENO]);
		close(aux->command->io[STDOUT_FILENO]);
		aux = aux->next;
	}
	while (aux->next)
	{
		printf("closing after {%li, %li}\n", aux->command->io[STDIN_FILENO],
				aux->command->io[STDOUT_FILENO]);
		close(aux->command->io[STDIN_FILENO]);
		close(aux->command->io[STDOUT_FILENO]);
		aux = aux->next;
	}
}

static int	st_child_process(t_cmd_table *cmd_table,
					t_pushdown_automaton *parse_bot)
{
	int	io[2];
	char	**command;
//	char	**env;

	command = cmd_table->command->parsed;
	if (is_terminal2(parse_bot->env_list, &command[0]))
	{
		io[STDIN_FILENO] = cmd_table->command->io[STDIN_FILENO];
		io[STDOUT_FILENO] = cmd_table->command->io[STDOUT_FILENO];
		dup2(io[STDIN_FILENO], STDIN_FILENO);
		dup2(io[STDOUT_FILENO], STDOUT_FILENO);
//		env = ll_to_tab(parse_bot->env_list);
		execve(command[0], command, NULL);
//		free(env);
	}
	automaton_destroy(parse_bot);
	automaton_cmdt_destroy(&cmd_table);
	exit(1);
}
