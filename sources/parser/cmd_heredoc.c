/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/22 04:52:02 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static char	*st_get_input(t_pushdown_automaton *parse_bot, char *eof);
static void	st_child_process(int pipefd[2], t_pushdown_automaton *parse_bot,
				t_token *tokens, t_cmd_table **cmd_table);
static void	st_out_doc_lst(t_llist **doc_lst, int fd);

int	cmd_heredoc(t_pushdown_automaton *parse_bot, t_token *tokens,
		t_cmd_table **cmd_table)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (STDIN_FILENO);
	if (pid == 0)
		st_child_process(pipefd, parse_bot, tokens, cmd_table);
	else
	{
		handle_no_signals();
		waitpid(pid, &status, 0);
		close(pipefd[STDOUT_FILENO]);
		handle_signals();
		get_status(status);
	}
	return (pipefd[STDIN_FILENO]);
}

static void	st_child_process(int pipefd[2], t_pushdown_automaton *parse_bot,
		t_token *tokens, t_cmd_table **cmd_table)
{
	t_llist	*doc_lst;

	doc_lst = NULL;
	handle_heredoc_signals();
	close(pipefd[STDIN_FILENO]);
	get_pipe(pipefd[STDOUT_FILENO]);
	cmdt_destroy(cmd_table);
	stck_rmv(parse_bot->stack);
	parse_bot->stack = NULL;
	while (1)
	{
		if (!ll_add_back(&doc_lst, ll_node(st_get_input(parse_bot,
						tokens->value))))
			break ;
	}
	st_out_doc_lst(&doc_lst, pipefd[STDOUT_FILENO]);
	close(pipefd[STDOUT_FILENO]);
	ll_clear(&doc_lst);
	automaton_destroy(parse_bot);
	token_free(&tokens);
	exit(get_status(-1));
}

static char	*st_get_input(t_pushdown_automaton *parse_bot, char *eof)
{
	char	*line;

	if (!eof)
		return (FALSE);
	line = readline("> ");
	if (!line)
	{
		printf(HERE_ERROR, parse_bot->input_count, eof);
	}
	if (str_len_until(line, '$') != FALSE_INDEX)
		line = expand_variable(parse_bot->env_list, line);
	if (str_comp(line, eof) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static void	st_out_doc_lst(t_llist **doc_lst, int fd)
{
	t_llist	*aux;

	aux = *doc_lst;
	while (aux)
	{
		put_str(aux->value, fd);
		put_char('\n', fd);
		aux = aux->next;
	}
}

int	get_pipe(int fd)
{
	static int	pipefd = -1;

	if (fd != -1)
		pipefd = fd;
	return (pipefd);
}
