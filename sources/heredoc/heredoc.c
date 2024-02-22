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

static void	st_get_input(t_llist *env, char *eof, int *fd);
static void	st_out_doc_lst(t_llist **doc_lst, int fd);
static char	*st_find_eof(t_token *tokens, int current);

// void	heredoc(t_llist *env_lst, t_token *tokens, t_cmd_table *cmd)
// {
// 	t_cmd_table	*aux;
// 	int			current;
// 	int			pipefd[2];
// 	pid_t			pid;

// 	aux = cmd;
// 	current = 0;
// 	pipe(pipefd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		handle_heredoc_sig(pid);
// 		close(pipefd[STDIN_FILENO]);
// 		while (aux)
// 		{
// 			if (cmd->command->io[STDIN_FILENO] == FD_HEREDOC)
// 			{
// 				st_get_input(env_lst, st_find_eof(tokens, current++),
// 								pipefd[STDOUT_FILENO], cmd);
// 				close(pipefd[STDOUT_FILENO]);
// 				if (!cmd)
// 					break ;
// 			}
// 			aux = aux->next;
// 		}
// 		close(pipefd[STDOUT_FILENO]);
// 		exit(0);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		handle_signals();
// 		close(pipefd[STDIN_FILENO]);
// 		close(pipefd[STDOUT_FILENO]);
// 		cmd->command->io[STDIN_FILENO] = pipefd[0];
// 	}
// }

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
				pipefd);
			close(pipefd[STDOUT_FILENO]);
			cmd->command->io[STDIN_FILENO] = pipefd[STDIN_FILENO];
		}
		aux = aux->next;
	}
	handle_signals();
}

static char	*st_find_eof(t_token *tokens, int current)
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

static void	st_get_input(t_llist *env, char *eof, int *fd)
{
	t_llist	*doc_lst;
	pid_t	pid;

	if (!eof)
		return ;
	pid = fork();
	if (pid == 0)
	{	
		close(fd[STDIN_FILENO]);
		handle_heredoc_sig(fd);
		doc_lst = NULL;
		run_heredoc(&doc_lst, env, eof);
		if (doc_lst)
		{
			st_out_doc_lst(&doc_lst, fd[STDOUT_FILENO]);
			ll_clear(&doc_lst);
		}
		close(fd[STDOUT_FILENO]);
		exit(0);
	}
	wait(NULL);
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
