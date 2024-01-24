/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/24 17:08:10 by nprudenc         ###   ########.fr       */
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

// static int	st_find_size(char *line, char *var_value)
// {	
// 	int	i;
// 	int	var_len;

// 	i = -1;
// 	while (line[++i])
// 	{
// 		if (line[i] == '$')
// 		{	
// 			var_len = str_len_until(&line[i + 1], ' ');
// 			if (var_len != FALSE_INDEX)
// 				return (str_len(line) - var_len + str_len(var_value));
// 			else
// 			{
// 				var_len = str_len_until(&line[i], '\0'); 
// 				return (str_len(line) - var_len + str_len(var_value));
// 			}
// 		}
// 	}
// 	return (str_len(line));
// }

// static char	*st_validate_var(char *line, char *var_value)
// {
// 	int		size;
// 	char	*output;

// 	size = st_find_size(line, var_value);
// 	output = mem_calloc(size + 1, sizeof(char));
// 	st_replace_var(line, output, var_value);
// 	free(line);
// 	return (output);
// }

void	heredoc(t_lst *env_lst, char *eof, int fd)
{
	char		*line;
	char		*aux;
	t_lst		*doc_lst;

	doc_lst = NULL;
	while (1)
	{
		line = readline("> ");
		aux = env_expand_variables(line, env_lst);
		if (aux)
		{
			free(line);
			line = aux;
		}
		// else
		// 	line = st_validate_var(line, " ");
		if (str_comp(line, eof) == 0)
		{	
			free(line);
			break ;
		}
		lst_add_back(&doc_lst, lst_new(line));
		// SIGABRT when free line??
		// free(line);
	}
	out_doc_lst(&doc_lst, fd);
	clear_lst(&doc_lst);
}