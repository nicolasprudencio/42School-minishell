/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:14 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/12 17:13:55 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_unset(t_env_lst **lst, char *var)
{
	t_env_lst	*aux;
	t_env_lst	*head;
	t_env_lst	*next;
	
	aux = *lst;
	head = *lst;
	while (aux)
	{	
		if (aux->next)
			next = aux->next;
		if (str_comp_until(head->value, var, '=') == TRUE)
		{
			*lst = next;
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