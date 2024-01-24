/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:14 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/24 13:16:37 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_unset(t_lst **llist, char *var)
{
	t_lst	*aux;
	t_lst	*head;
	t_lst	*next;
	
	aux = *llist;
	head = *llist;
	while (aux)
	{	
		if (aux->next)
			next = aux->next;
		if (str_comp_until(head->value, var, '=') == TRUE)
		{
			*llist = next;
			lst_del_one(head);
			return (TRUE);
		}
		if (str_comp_until(next->value, var, '=') == TRUE)
		{
			aux->next = next->next;
			lst_del_one(next);
			return (TRUE);
		}
		aux = aux->next;
	}
	return (FALSE);
}
