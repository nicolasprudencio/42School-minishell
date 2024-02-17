/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/16 16:58:17 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_to_replace(t_llist **ll, char *var)
{
	t_llist *aux;

	aux = *ll;
	while (aux)
	{	
		if (str_comp_until(aux->value, var, '=') == TRUE)
		{
			free(aux->value);
			aux->value = str_dup(var);
			return (TRUE);
		}
		aux = aux->next;
	}
	return (FALSE);
}

int	exec_export(t_llist *ll, char *var, int fd)
{
	t_llist	*aux;

	aux = ll;
	if (var)
	{	
		if (st_to_replace(&ll, var) == TRUE)
			return (TRUE);
		else
			ll_add_back(&ll, ll_node(var));
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
