/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:14 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/16 15:36:24 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_unset(t_llist **llist, char *var)
{
	t_llist	*aux;
	t_llist	*head;
	t_llist	*next;
	
	aux = *llist;
	head = *llist;
	while (aux)
	{	
		if (aux->next)
			next = aux->next;
		if (str_comp_until(head->value, var, '=') == TRUE)
		{
			*llist = next;
			ll_del_one(head);
			return (TRUE);
		}
		if (str_comp_until(next->value, var, '=') == TRUE)
		{
			aux->next = next->next;
			ll_del_one(next);
			return (TRUE);
		}
		aux = aux->next;
	}
	return (FALSE);
}
