/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/15 15:25:57 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	out_doc_lst(t_lst **doc_lst, int fd)
{
	t_lst	*aux;
	
	aux = *doc_lst;
	while (aux)
	{
		put_str(aux->value, fd);
		put_char('\n', fd);
		aux = aux->next;
	}
}

void	heredoc(t_lst *env_lst, char *eof, int fd)
{
	char	*line;
	t_lst	*doc_lst;

	doc_lst = NULL;
	while (1)
	{
		line = readline("> ");
		// if (!line)
		// {
			// c+d signal exit heredoc
		// }
		if (str_len_until(line, '$') != FALSE_INDEX)
			line = expand_variable(env_lst, line);
		if (str_comp(line, eof) == 0)
		{	
			free(line);
			break ;
		}
		lst_add_back(&doc_lst, lst_new(line));
		free(line);
	}
	out_doc_lst(&doc_lst, fd);
	clear_lst(&doc_lst);
}