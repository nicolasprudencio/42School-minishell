#include "libseas.h"

static void	st_check_initial_fd(t_cmd_table **cmd_table, int fd);
static int	st_check_for_recursion(t_pushdown_automaton *parse_bot,
				t_cmd_table **cmd_table);

int	core(t_pushdown_automaton *parse_bot, char *prompt, int fd)
{
	int	recursive_case;
	char	*rl_output;
	t_token	*tokens;
	t_cmd_table	*cmd_table;

	handle_signals();
	rl_output = readline(prompt);
	add_history(rl_output);
	tokens = lexer(rl_output, parse_bot);
	if (!tokens)
		return (FALSE);
	cmd_table = parser(parse_bot, tokens);
	heredoc(parse_bot->env_list, tokens, cmd_table);
	token_free(&tokens);
	if (!cmd_table)
		return (FALSE);
	st_check_initial_fd(&cmd_table, fd);
//	open heredoc
	recursive_case = st_check_for_recursion(parse_bot, &cmd_table);
	free(rl_output);
	exec(&cmd_table, parse_bot);
	if (recursive_case)
		core(parse_bot, "> ", recursive_case);
	cmdt_destroy(&cmd_table);
	return (TRUE);
}

static void	st_check_initial_fd(t_cmd_table **cmd_table, int fd)
{
	t_cmd_table	*last;

	cmd_last(&last, cmd_table);
	if (last->command->io[STDIN_FILENO] == STDIN_FILENO)
		last->command->io[STDIN_FILENO] = fd;
	else if (fd != STDIN_FILENO)
		close(fd);
}

static int	st_check_for_recursion(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table)
{
	t_cmd_table	*recursion_helper;
	t_command	*cmd_o;
	int		pipefd[2];

	if (parse_bot->current_state == PIPE_EMPTY)
	{
		if (pipe(pipefd))
			return (FALSE);
		cmd_last(&recursion_helper, cmd_table);
		cmd_o = recursion_helper->command;
		if (cmd_o->io[STDOUT_FILENO] == STDOUT_FILENO)
			cmd_o->io[STDOUT_FILENO] = pipefd[STDOUT_FILENO];
		else
		{
			printf("st_check_for_recursion closing fd: %i\n", 
					pipefd[STDOUT_FILENO]);
			close(pipefd[STDOUT_FILENO]);
		}
		return (pipefd[STDIN_FILENO]);
	}
	return (FALSE);
}

