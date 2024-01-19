/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:14 by fpolaris          #+#    #+#             */
/*   Updated: 2024/01/17 20:27:18 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static char	*st_find_path_variable(t_llist *env_lst)
{
	t_llist	*aux;
	char	*var;
	char	*var_value;

	aux = env_lst;
	while (aux)
	{
		if (str_comp_until(aux->value, "PATH", '=') == TRUE)
		{	
			var = str_find_char(aux->value, '=', 1);
			var_value = mem_calloc(str_len(var), sizeof(char));
			if (!var_value)
				return (NULL);
			var_value = var;
			return (var_value);
		}	
		aux = aux->next;
	}
	return (NULL);
}

int	is_terminal(t_llist *env_lst, char *line)
{	
	char	*path_value;
	char	**paths;
	int		i;

	if (access(line, X_OK) == 0)
		return (TRUE);
	path_value = st_find_path_variable(env_lst);
	if (!path_value)
		return (FALSE);
	paths = str_split(path_value, ':');
	i = -1;
	while (paths[++i])
	{
		paths[i] = str_join(paths[i], "/", 1);
		paths[i] = str_join(paths[i], line, 1);		
		if (access(paths[i], X_OK) == 0)
		{
			grid_free(paths);
			return (TRUE);
		}
	}
	i = -1;
	grid_free(paths);
	return (FALSE);
}

int	is_terminal2(t_llist *env_lst, char **line)
{	
	char	*path_value;
	char	**paths;
	int		i;

	if (access(*line, X_OK) == 0)
		return (TRUE);
	path_value = st_find_path_variable(env_lst);
	if (!path_value)
		return (FALSE);
	paths = str_split(path_value, ':');
	i = -1;
	while (paths[++i])
	{
		paths[i] = str_join(paths[i], "/", 1);
		paths[i] = str_join(paths[i], *line, 1);		
		if (access(paths[i], X_OK) == 0)
		{
			free(*line);
			*line = str_dup(paths[i]);
			grid_free(paths);
			return (TRUE);
		}
	}
	i = -1;
	grid_free(paths);
	return (FALSE);
}
