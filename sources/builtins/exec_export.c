/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/19 14:21:06 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_to_replace(t_lst	**lst, char *var)
{
	t_lst *aux;

	aux = *lst;
	while (aux)
	{	
		if (is_valid_env(aux->value, var, '=') == TRUE)
		{
			free(aux->value);
			aux->value = str_dup(var);
			return (TRUE);
		}
		aux = aux->next;
	}
	return (FALSE);
}

int	exec_export(t_lst *lst, char *var, int fd)
{
	t_lst	*aux;

	aux = lst;
	if (var)
	{	
		if (st_to_replace(&lst, var) == TRUE)
			return (TRUE);
		else
			lst_add_back(&lst, lst_new(var));
		return (TRUE);
	}
	while (aux)
	{	
		put_str("declare -x ", fd);
		put_str(aux->value, fd);
		if (aux->value[str_len_until(aux->value, '=') + 1] == '\0')
			put_str("\"\"", fd);
		put_str("\n", fd);	
		aux = aux->next;
	}
	return (TRUE);
}
