/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:05:24 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/16 20:00:30 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

// static int	chars_count(char *str, char c, char c2)
// {
// 	int	i;
// 	int	counter;

// 	i = -1;
// 	counter = 0;
// 	while (str[++i])
// 	{
// 		if (str[i] == c || str[i] == c2)
// 			counter++;
// 		if ((str[i] == c && str[i + 1] == c2) || (str[i] == c2 && str[i + 1] == c))
// 			counter--;
// 	}
// 	return (counter);
// }

// static char	**arr_define(char *str, char **arr, char c, char c2)
// {	
// 	int	i;
// 	int	index_len;
// 	char *pointer;

// 	i = -1;
// 	pointer = str;
// 	index_len = 0;
// 	while (str[++i])
// 	{
// 		if (str[i] == c)
// 		{
// 			while (pointer && *pointer == c)
// 				pointer++;
// 			arr[index_len] = str_copy_upto(pointer, c);
// 			index_len++;
// 			pointer = str_find_char(pointer, c, 0);
// 		}
// 		if (str[i] == c2)
// 		{
// 			while (pointer && *pointer == c2)
// 				pointer++;
// 			arr[index_len] = str_copy_upto(pointer, c2);
// 			pointer = str_find_char(pointer, c2, 0);
// 		}
// 	}
// 	return (arr);
// }

// static char	**str_split_bytwo(char *str, char c, char c2)
// {
// 	int		i;
// 	char	**arr;
// 	int		index_len;

// 	i = -1;
// 	index_len = chars_count(str, c, c2) + 1;
// 	if (str[0] == c || str[0] == c2)
// 		index_len--;
// 	if (str[str_len(str) - 1] == c || str[str_len(str) - 1] == c2)
// 		index_len--;
// 	arr = (char **)mem_calloc(index_len, sizeof (char *));
// 	if (!arr)
// 		return (NULL);
// 	arr = arr_define(str, arr, c, c2);
// 	arr[index_len] = "\0";
// 	return (arr);
// }

// static int	change_var_value(char **line, t_lst *lst)
// {	
// 	t_lst *aux;
// 	int		checker;
// 	int		i;

// 	i = -1;
// 	aux = lst;
// 	while (line[++i])
// 	{	
// 		checker = str_len_until(line[i], '$');
// 		if (checker != FALSE_INDEX && str_len(line[i]) > 1)
// 			while (aux)
// 			{	
// 				if (str_comp_until(&line[i][checker + 1], aux->value, 1) == TRUE)
// 				{
// 					free(line[i]);
// 					line[i] = str_dup(str_find_char(aux->value, '=', 0));
// 					return (TRUE);
// 				}	
// 				aux = aux->next;
// 			}
// 	}
// 	return (FALSE);
// }

// static char *str_from_array(char **arr)
// {
// 	int	i;
// 	char *str;

// 	i = -1;
// 	while (arr[++i])
// 		str = str_join(str, arr[i], 1);
// 	// free(arr);
// 	return (str);
// }

// char	*env_expand_variables(char	*line, t_lst *lst)
// {
// 	char		**str_arr;
// 	char		*output;
// 	int			i;

// 	i = -1;
// 	str_arr = NULL;
// 	if (str_len_until(line, '$') != FALSE_INDEX)
// 	{
// 		str_arr = str_split_bytwo(line, ' ', '\n');
// 		while (str_arr[++i])
// 			printf("%s\n", str_arr[i]);
// 		change_var_value(str_arr, lst);	
// 		output = str_from_array(str_arr);
// 	}
// 	if (str_arr)
// 		return (output);
// 	return (NULL);
// }

char	*env_expand_variables(char *line, t_lst *lst)
{
	t_lst	*aux;
	char	*var;
	int		i;

	aux = lst;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '$')
		{	
			if (str_len_until(&line[i + 1], ' ') != FALSE_INDEX)
				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], ' '));
			else
				var = str_ndup(&line[i + 1], str_len_until(&line[i + 1], '\0'));
		}
	}
	while (aux)
	{
		if (str_comp_until(aux->value, var, '=') == TRUE)
		{	
			free(var);
			return (str_find_char(aux->value, '=', 1));
		}
		aux = aux->next;
	}
	return (NULL);
}