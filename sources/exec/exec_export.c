/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/16 15:36:24 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_to_replace(t_llist **llist, char *var)
{
	t_llist *aux;
	t_llist *temp;

	aux = *llist;
	temp = *llist;
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

int	exec_export(t_llist *llist, char *var, int fd)
{
	t_llist	*aux;

	aux = llist;
	if (var)
	{	
		if (st_to_replace(&llist, var) == TRUE)
			return (TRUE);
		else
			ll_add_back(&llist, ll_node(var));
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
