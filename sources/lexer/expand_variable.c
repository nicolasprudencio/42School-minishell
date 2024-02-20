/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:01:00 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/20 15:35:58 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"
#include <stdlib.h>

static char	*st_replace_status(char *line, char *var, int before_len)
{
	int		var_len;
	char	*output;
	char	*var_value;

	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	var_value = str_copy_upto(var, '\0');
	var_len = str_len(var) + 1;
	output = str_join(output, var_value, 2);
	if (!output)
		return (line);
	output = str_join(output, &line[before_len + var_len], 1);
	if (!output)
		return (line);	
	free(line);
	return (output);
}

static char	*st_replace_word(char *line, char *var, int before_len)
{
	int		var_len;
	char	*output;
	char	*var_value;

	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	var_value = str_copy_upto(str_find_char(var, '=', 1), '\0');
	var_len = str_len_until(var, '=') + 1;
	output = str_join(output, var_value, 2);
	if (!output)
		return (line);
	output = str_join(output, &line[before_len + var_len], 1);
	if (!output)
		return (line);
	free(line);
	return (output);
}

static char	*st_remove_word(char *line, int rest_len)
{
	int		before_len;
	char	*output;

	before_len = str_len(line) - rest_len;
	output = str_ndup(line, before_len);
	if (!output)
		return (line);
	while(line[before_len++] && !is_space(line[before_len]) && line[before_len] != '$')
		;
	output = str_join(output, &line[before_len], 1);
	if (!output)
		return (line);
	free(line);
	return (output);
}

static char	*st_var_exists(t_llist *lst, char *var)
{	
	t_llist	*aux;

	aux = lst;
	while (aux)
	{
		if (is_valid_env(aux->value, &var[1], '='))
			return (aux->value);
		aux = aux->next;
	}
	return (NULL);
}

static int	get_digits_amount(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		while (n)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			n_size;
	long int	nb;

	n_size = get_digits_amount(n);
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		n_size++;
	}
	str = malloc((n_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_size] = '\0';
	while (n_size--)
	{
		str[n_size] = '0' + nb % 10;
		nb /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}

char	*expand_variable(t_llist *lst, char *line)
{
	char	*var;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && is_alpha(line[i + 1]))
		{
			var = st_var_exists(lst, &line[i]);
			if (var)
			{
				line = st_replace_word(line, var, i);
				while (line[i] && !is_space(line[i]) && line[i] != '$')
					i++;
			}
			else
				line = st_remove_word(line, str_len(&line[i]));
		}
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line = st_replace_status(line, ft_itoa(*get_status()), i);
			while (line[i] && !is_space(line[i]) && line[i] != '$')
				i++;
		}
		else
			i++;
	}
	return (line);
}
