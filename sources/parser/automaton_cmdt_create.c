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

static int	st_redirect_io(int state, t_cmd_table **cmd_table,
				t_token *token);
static int	st_heredoc(int state, t_cmd_table **cmd_table, t_token *token);

int	cmdt_create(int state, t_cmd_table **cmd_table, t_token *token)
{
	if (state == NEW_CMD)
	{
		if (!cmd_create(cmd_table, token))
			return (FALSE);
	}
	if (!(st_redirect_io(state, cmd_table, token)))
		return (FALSE);
	if (!st_heredoc(state, cmd_table, token))
		return (FALSE);
	return (TRUE);
}

static int	st_redirect_io(int state, t_cmd_table **cmd_table,
		t_token *token)
{
	if (state == PIPE_TO_CMD)
	{
		if (!cmd_create(cmd_table, token))
			return (FALSE);
		if (!cmd_pipe(cmd_table))
			return (FALSE);
	}
	else if (state == INPUT_REDIR)
	{
		if (!cmd_iredir(cmd_table, token))
			return (FALSE);
	}
	else if (state == OUTPUT_REDIR)
	{
		if (!cmd_oredir(cmd_table, token))
			return (FALSE);
	}
	else if (state == APPEND)
	{
		if (!cmd_append(cmd_table, token))
			return (FALSE);
	}
	return (TRUE);
}

static int	st_heredoc(int state, t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;

	cmd_last(&last, cmd_table);
	if (state == HEREDOC)
	{
		if (last->command->io[STDIN_FILENO] != STDIN_FILENO)
			close(last->command->io[STDIN_FILENO]);
		last->command->io[STDIN_FILENO] = FD_HEREDOC;
	}
	else if (state == INVALID_REDIR)
	{
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
