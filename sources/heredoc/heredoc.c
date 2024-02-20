/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/20 13:25:54 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void st_get_input(t_llist *env, char *eof, int fd);
static void	st_out_doc_lst(t_llist **doc_lst, int fd);
static char *st_find_eof(t_token *tokens, int current);

void	heredoc(t_llist *env_lst, t_token *tokens, t_cmd_table *cmd)
{
	t_cmd_table	*aux;
	int			current;
	int			pipefd[2];

	aux = cmd;
	current = 0;
	while (aux)
	{
		if (cmd->command->io[STDIN_FILENO] == FD_HEREDOC)
		{
			pipe(pipefd);
			st_get_input(env_lst, st_find_eof(tokens, current++),
							pipefd[STDOUT_FILENO]);
			close(pipefd[STDOUT_FILENO]);
			cmd->command->io[STDIN_FILENO] = pipefd[0];
		}
		aux = aux->next;
	}
}

static char *st_find_eof(t_token *tokens, int current)
{
	int		i;
	t_token	*aux;

	i = 0;
	aux = tokens;
	while (aux->next)
	{
		if (!str_comp(aux->value, "<<"))
		{
			if (i == current)
				return (aux->next->value);
			else
				i++;
		}
		aux = aux->next;
	}
	return (NULL);
}

static void st_get_input(t_llist *env, char *eof, int fd)
{
	char	*line;
	int		counter;
	t_llist	*doc_lst;

	doc_lst = NULL;
	counter = 0;
	if (!eof)
		return ;
	// handle_exec_signals();
	while (1)
	{
		line = readline("> ");
		counter++;
		if (!line)
		{
			printf("bash: warning: here-document at line %i delimited by end-of-file (wanted `%s')\n", counter, eof);
			if (doc_lst)
				ll_clear(&doc_lst);
			return ;	
		}
		if (str_len_until(line, '$') != FALSE_INDEX)
			line = expand_variable(env, line);
		if (str_comp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		ll_add_back(&doc_lst, ll_node(line));
		free(line);
	}
	st_out_doc_lst(&doc_lst, fd);
	ll_clear(&doc_lst);
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
