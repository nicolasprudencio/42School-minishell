/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:07:16 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/21 22:53:53 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_throw_exit(t_llist *doc_lst, int counter, char *eof)
{
	printf(HERE_ERROR, counter, eof);
	if (doc_lst)
		ll_clear(&doc_lst);
	get_status(0);
}

void	run_heredoc(t_llist **doc_lst, t_llist *env, char *eof)
{	
	char	*line;
	int		counter;

	counter = 0;
	while (1)
	{
		line = readline("> ");
		counter++;
		if (!line)
		{
			st_throw_exit(*doc_lst, counter, eof);
			break ;
		}
		if (str_len_until(line, '$') != FALSE_INDEX)
			line = expand_variable(env, line);
		if (str_comp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		ll_add_back(doc_lst, ll_node(line));
		free(line);
	}
}
