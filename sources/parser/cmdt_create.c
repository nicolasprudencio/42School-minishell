/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_cmdt_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:25:19 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:25:20 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_check_states1(t_pushdown_automaton *parse_bot,
				t_cmd_table **cmd_table, t_token *token);
static int	st_check_states2(t_pushdown_automaton *parse_bot,
				t_cmd_table **cmd_table, t_token *token);

int	cmdt_create(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;

	if (parse_bot->current_state == NEW_CMD)
	{
		if (!cmd_create(cmd_table, token))
			return (FALSE);
	}
	if (!(st_check_states1(parse_bot, cmd_table, token)))
		return (FALSE);
	if (!st_check_states2(parse_bot, cmd_table, token))
		return (FALSE);
	if (parse_bot->current_state == INVALID_REDIR)
	{
		cmd_last(&last, cmd_table);
		if (!token)
			printf("%s '%s'\n", STD_ERROR, "newline");
		else
			printf("%s '%s'\n", STD_ERROR, token->value);
		free(last->command->parsed[0]);
		last->command->parsed[0] = str_dup("(Invalid)");
		return (FALSE);
	}
	return (TRUE);
}

static int	st_check_states1(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	if (parse_bot->current_state == PIPE_TO_CMD)
	{
		if (!cmd_create(cmd_table, token))
			return (FALSE);
		if (!cmd_pipe(cmd_table))
			return (FALSE);
	}
	else if (parse_bot->current_state == INPUT_REDIR)
	{
		if (!cmd_iredir(cmd_table, token))
			return (FALSE);
	}
	else if (parse_bot->current_state == OUTPUT_REDIR)
	{
		if (!cmd_oredir(cmd_table, token))
			return (FALSE);
	}
	else if (parse_bot->current_state == APPEND)
	{
		if (!cmd_append(cmd_table, token))
			return (FALSE);
	}
	return (TRUE);
}

static int	st_check_states2(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;
	int			here_fd;

	cmd_last(&last, cmd_table);
	if (parse_bot->current_state == HEREDOC)
	{
		if (last->command->io[STDIN_FILENO] != STDIN_FILENO)
			close(last->command->io[STDIN_FILENO]);
		here_fd = cmd_heredoc(parse_bot, token, cmd_table);
		if (here_fd == -1)
		{
			free(last->command->parsed[0]);
			last->command->parsed[0] = str_dup("(Invalid)");
		}
		last->command->io[STDIN_FILENO] = here_fd;
	}
	return (TRUE);
}
