#include "libseas.h"

static int	st_redirect_io(int state, t_cmd_table **cmd_table,
		t_token *token);
static int	st_heredoc(int state, t_cmd_table **cmd_table, t_token *token);

int	automaton_cmdt_create(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	if (parse_bot->current_state == NEW_CMD)
	{
		if (!automaton_cmd_create(cmd_table, token))
			return (FALSE);
	}
	if (!(st_redirect_io(parse_bot->current_state, cmd_table, token)))
		return (FALSE);
	if (!st_heredoc(parse_bot->current_state, cmd_table, token))
		return (FALSE);
	return (TRUE);
}

static int	st_redirect_io(int state, t_cmd_table **cmd_table,
		t_token *token)
{
	if (state == PIPE_TO_CMD)
	{
		if (!automaton_cmd_create(cmd_table, token))
			return (FALSE);
		if (!automaton_cmd_pipe(cmd_table))
			return (FALSE);
	}
	else if (state == INPUT_REDIR)
	{
		if (!automaton_cmd_iredir(cmd_table, token))
			return (FALSE);
	}
	else if (state == OUTPUT_REDIR)
	{
		if (!automaton_cmd_oredir(cmd_table, token))
			return (FALSE);
	}
	else if (state == APPEND)
	{
		if (!automaton_cmd_append(cmd_table, token))
			return (FALSE);
	}
	return (TRUE);
}

static int	st_heredoc(int state, t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;

	automaton_cmd_last(&last, cmd_table);
	if (state == HEREDOC)
	{
		if (last->command->io[STDIN_FILENO] != STDIN_FILENO)
			close(last->command->io[STDIN_FILENO]);
		last->command->io[STDIN_FILENO] = FD_HEREDOC;
	}
	else if (state == INVALID_REDIR)
	{
		if (!token)
			printf("STD_ERROR %s\n", "newline");
		else
			printf("STD_ERROR %s\n", token->value);
		free(last->command->parsed[0]);
		last->command->parsed[0] = str_dup("(Invalid)");
		return (FALSE);
	}
	return (TRUE);
}
