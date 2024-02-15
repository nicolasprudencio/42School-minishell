/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:01:00 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/15 15:06:59 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static char	*str_dup_len(char *s, int len)
{
	char	*s2;
	int		i;

	s2 = (char *)mem_calloc(len, sizeof(char)) + 1;
	i = -1;
	while (++i < len)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}

static char	*ft_strstr(const char* pointer, const char* word)
{	
	const char* h;
	const char* n;
	
	while (*pointer)
	{
		h = pointer;
		n = word;
		while (*pointer && *n && *pointer == *n)
		{
			pointer++;
			n++;
		}	
		if (!*n) {
			return (char*)h;
		}	
		pointer = h + 1;
	}	
	return NULL;
}

static char	*replace_word(char *str, char *target, const char *replacement)
{
	char *pos;

	pos = str;
	// printf("bef: %s\n", pos);
	pos = ft_strstr(pos, target);
	// printf("after: %s\n", pos);
	// mem_move(pos + str_len(replacement), pos + str_len(target), str_len(pos + str_len(target)) + 1);
	mem_cpy(pos, replacement, str_len(replacement));
	pos += str_len(replacement);
	return (str);
}

void	expand_variable(char *line, char *var)
{
	char	*to_replace;
	char	*temp;

	temp = str_copy_upto(str_find_char(var, '=', 1), '\0');
	to_replace = str_dup_len(line, str_len_until(var, '=') + 1);
	// printf("temp: %s\n", temp);
	// printf("replace: %s\n", to_replace);
	// printf("line: %s\n", line);

	replace_word(line, to_replace, temp);
}

void	check_if_variable(t_lst *lst, char *line)
{
	t_lst	*aux;
	char	*str;

	
	if (str_len_until(line, '$') != FALSE_INDEX)
	{
		aux = lst;
		str = str_find_char(line, '$', 0);
		while (aux)
		{
			if (str_comp_until(aux->value, &str[1], '='))
			{
				expand_variable(str, aux->value);
				check_if_variable(lst, line);
			}
			aux = aux->next;
		}
	}
	return ;
}