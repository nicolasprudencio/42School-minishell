/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/18 12:14:05 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	out_doc_lst(t_lst **doc_lst, int fd)
{
	t_lst	*aux;
	
	aux = *doc_lst;
	while (aux)
	{
		put_str(aux->value, fd);
		put_char('\n', fd);
		aux = aux->next;
	}
	clear_lst(doc_lst);
}

static int	st_find_size(char *line, char *var_value)
{	
	int	i;
	int	var_len;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '$')
		{	
			var_len = str_len_until(&line[i + 1], ' ');
			if (var_len != FALSE_INDEX)
				return (str_len(line) - var_len + str_len(var_value));
			else
			{
				var_len = str_len_until(&line[i], '\0'); 
				return (str_len(line) - var_len + str_len(var_value));
			}
		}
	}
	return (str_len(line));
}

char 	*replace_var(char *line, char *var_value)
{	
	int		i;
	int		j;
	int		k;
	int		size;
	char	*out;

	size = st_find_size(line, var_value);
	out = mem_calloc(size + 1, sizeof(char));
	i = -1;
	j = -1;
	k = 0;
	while (line[++i])
	{
		if (line[i] == '$')
		{
			k = i;
			while (var_value[++j])
			{
				out[k] = var_value[j];
				k++;
			}
			while (line[i] != '\0' && line[i] != ' ')
				i++;
			k = str_len(out);	
		}
		out[k++] = line[i];
	}
	out[k] = '\0';
	free(line);
	return (out);
}

void	heredoc(t_lst *env_lst, char *eof, int fd)
{
	char		*line;
	char		*env_var;
	t_lst		*aux;
	t_lst		*doc_lst;
	
	doc_lst = NULL;
	while (1)
	{
		aux = env_lst;
		line = readline("> ");
		env_var = env_expand_variables(str_find_char(line, '$', 0), env_lst);
		if (env_var)
			line = replace_var(line, env_var);
		if (str_comp(line, eof) == 0)
		{	
			free(line);
			break ;
		}
		lst_add_back(&doc_lst, lst_new(line));
		free(line);
	}
	out_doc_lst(&doc_lst, fd);
}