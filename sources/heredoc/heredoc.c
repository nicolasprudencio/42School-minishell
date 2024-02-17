/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/16 16:54:24 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	out_doc_lst(t_llist **doc_lst, int fd)
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

void	heredoc(t_llist *env_lst, char *eof, int fd)
{
	char	*line;
	t_llist	*doc_lst;

	doc_lst = NULL;
	while (1)
	{
		line = readline("> ");
		if (str_len_until(line, '$') != FALSE_INDEX)
			line = expand_variable(env_lst, line);
		if (str_comp(line, eof) == 0)
		{	
			free(line);
			break ;
		}
		ll_add_back(&doc_lst, ll_node(line));
		free(line);
	}
	out_doc_lst(&doc_lst, fd);
	ll_clear(&doc_lst);
}
