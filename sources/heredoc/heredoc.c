/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/16 20:04:33 by nprudenc         ###   ########.fr       */
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

// char 	*replace_var(char *line, char *var_value)
// {	
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		size;
// 	char	*aux;

// 	size = st_find_size(line, var_value);
// 	aux = mem_calloc(size + 1, sizeof(char));
// 	i = -1;
// 	j = -1;
// 	while (line[++i])
// 	{
// 		if (line[i] == '$')
// 		{
// 			while (var_value[++j])
// 			{
// 				k = i;
// 				aux[k] = var_value[j];
// 				k++;
// 			}
// 			while (line[++i] != ' ' || line[i] != '\0')
// 				;
// 		}
// 		aux[i] = line[i];
// 	}
// 	aux[i] = '\0';
// 	free(line);
// 	return (aux);
// }

// int		check_if_var(char *line, t_lst *env_lst)
// {	
// 	int		i;
// 	char	*var_value;

// 	i = str_len_until(line, '$');
// 	if (i < 0)
// 		return (FALSE_INDEX);
// 	if (is_alpha(line[i + 1]))
// 	{
// 		var_value = env_expand_variables(str_find_char(line, '$', 1), env_lst);
// 		if (var_value)
// 			return (TRUE);
// 	}
// 	return (FALSE);
// }

void	here_doc(t_lst *env_lst, char *eof, int fd)
{
	char		*line;
	// char		*env_var;
	t_lst		*aux;
	t_lst		*doc_lst;
	
	doc_lst = NULL;
	while (1)
	{
		aux = env_lst;
		line = readline("> ");
		printf("%s\n", env_expand_variables(line, env_lst));
		// if (check_if_var(line, env_lst))
		// 	line = replace_var(line, env_expand_variables(str_find_char(line, '$', 1), env_lst));
		lst_add_back(&doc_lst, lst_new(line));
		if (str_comp(line, eof) == 0)
		{	
			free(line);
			break ;
		}
		free(line);
	}
	out_doc_lst(&doc_lst, fd);	
	// printf("%s\n", env_expand_variables("$HOME", lst));
}