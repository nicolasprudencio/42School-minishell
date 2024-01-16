/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:48:24 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/16 15:36:24 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_lst	*lst_new(char *value)
{
	t_lst *new;

	new = (t_lst *)mem_calloc(1, sizeof(t_lst));
	if (!new)
		return (NULL);
	new->value = str_dup(value);
	new->next = NULL;
	return (new);	
}

void	lst_del_one(t_lst *lst)
{
	free(lst->value);
	free(lst);
}

void	lst_add_back(t_lst	**lst, t_lst *new)
{
	t_lst	*aux;

	if (!*lst)
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}	
}

t_lst	*new_lst(char **variables)
{
	int	i;
	t_lst *lst;

	i = -1;
	lst = NULL;
	while (variables[++i])
		lst_add_back(&lst ,lst_new(variables[i]));
	return (lst);	
}

void	clear_lst(t_lst **lst)
{
	t_lst *aux;
	t_lst *temp;

	aux = *lst;
	while (aux)
	{	
		temp = aux->next;
		free(aux->value);
		free(aux);
		aux = temp;
	}
	// free(lst);
}