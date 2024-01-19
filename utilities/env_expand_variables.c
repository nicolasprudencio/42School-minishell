/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:05:24 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/19 19:05:43 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	fp_is_count(char *str, int (*is)(int))
{
	int	i;
	int	output;

	if (!str)
		return (0);
	output = 0;
	i = -1;
	while (str[++i])
	{
		if (is(str[i]))
			output++;
	}
	return (output);
}

static char *str_copy_upis(char *str, int (*is)(int))
{
	char	*output;
	int		i;

	if (!str)
		return (NULL);
	output = (char *)mem_calloc(str_len(str) + 1, sizeof(char));
	if (!output)
		return (NULL);
	i = -1;
	while (str[++i] && !is(str[i]))
		output[i] = str[i];
	return (output);
}

static char	*str_find_is(const char *s, int (*is)(int), int jump)
{
	int	i;
	size_t	len;

	i = -1;
	len = str_len(s);
	while (s[++i] && !is(s[i]))
		;
	if (s[i] && is(s[i]) && jump < (int)len - i)
		return ((char *)&s[i + jump]);
	return ((char *)&s[i]);
}

static char	**str_split_is(char *str, int (*is)(int))
{
	char	**output;
	char		*p;
	int			grid_size;
	int			i;

	if (!str)
		return (NULL);
	grid_size = fp_is_count(str, is) + 1;
	if (is(str[0]))
		grid_size--;
	if (is(str[str_len(str) - 1]))
		grid_size--;
	output = (char **)mem_calloc(grid_size + 1, sizeof(char *));
	if (!output)
		return (NULL);
	p = (char *)str;
	i = -1;
	while (++i < grid_size)
	{
		while (p && is(str[i]))
			p++;
		output[i] = str_copy_upis(p, is);
		p = str_find_is(p, is, 1);
	}
	return (output);
}

// static int	change_var_value(char **line, t_lst *lst)
// {	
// 	t_lst *aux;
// 	int		checker;
// 	int		i;

// 	i = -1;
// 	while (line[++i])
// 	{	
// 		aux = lst;
// 		checker = str_len_until(line[i], '$');
// 		if (checker != FALSE_INDEX && str_len(line[i]) > 1)
// 		{
// 			while (aux)
// 			{	
// 				if (str_comp_until(aux->value, &line[i][1], '='))
// 				{
// 					free(line[i]);
// 					line[i] = str_dup(str_find_char(aux->value, '=', 1));
// 				}
// 				aux = aux->next;
// 			}
// 		}
// 	}
// 	return (TRUE);
// }

static int	change_var_value(char **line, t_lst *lst)
{	
	t_lst	*aux;
	char	*new_line;
	int		i;
	int		j;

	i = -1;
	new_line = NULL;
	while (line[++i])
	{
		j = -1;
		aux = lst;
		if (str_len_until(line[i], '$') == TRUE)
			new_line = str_copy_upto(line[i], '$');
		while (line[i][++j])
		{
			while (aux)
			{
				if (str_comp_until(aux->value, &line[i][j], '='))
					new_line = str_join(new_line, aux->value, 1);
				aux = aux->next;
			}
			if (new_line)
			{
				free(line[i]);
				line[i] = new_line;
			}
		}
	}
	return (TRUE);
}

static char *str_from_array(char **arr)
{
	int	i;
	char	*str;

	i = -1;
	str = NULL;
	while (arr[++i])
		str = str_join(str, arr[i], 1);
	return (str);
}

char	*env_expand_variables(char	*line, t_lst *lst)
{
	char		**str_arr;
	char		*output;
	int			i;
	i = -1;
	str_arr = NULL;
	if (str_len_until(line, '$') != FALSE_INDEX)
	{
		str_arr = str_split_is(line, is_space);
		// while (str_arr[++i])
		// 	printf("%s\n", str_arr[i]);
		change_var_value(str_arr, lst);	
		output = str_from_array(str_arr);
	}
	if (str_arr)
		return (output);
	return (NULL);
}

// char	*check_variable(char *line)
// {
// 	int		i;
// 	char	*var;

// 	i = -1;
// 	var = NULL;
// 	while (line[++i])
// 	{
// 		if (line[i] == '$')
// 		{	
// 			if (str_len_until(&line[i + 1], ' ') != FALSE_INDEX)
// 				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], ' '));
// 			else if (str_len_until(&line[i + 1], '\n') != FALSE_INDEX)
// 				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], '\\'));	
// 			else
// 				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], '\0'));
// 		}
// 	}
// 	return (var);
// }

// char	*env_expand_variables(char *line, t_lst *lst)
// {
// 	t_lst	*aux;
// 	char	*var;

// 	aux = lst;
// 	var = check_variable(line);
// 	if (var)
// 	{
// 		while (aux)
// 		{
// 			if (str_comp_until(var, aux->value, '\\') || str_comp_until(aux->value, var, '='))
// 			{	
// 				free(var);
// 				return (str_find_char(aux->value, '=', 1));
// 			}
// 			aux = aux->next;
// 		}
// 	}
// 	return (NULL);
// }