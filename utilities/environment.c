/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:48:24 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/09 20:49:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static t_env_lst	*lst_new(char *value)
{
	t_env_lst *new;

	new = (t_env_lst *)mem_calloc(1, sizeof(t_env_lst));
	if (!new)
		return (NULL);
	new->value = str_dup(value);
	new->next = NULL;
	return (new);	
}

static void	lst_add_back(t_env_lst	**lst, t_env_lst *new)
{
	t_env_lst	*aux;

	if (!*lst)
		*lst = new;
	else
	{
		aux = *lst;
		if (aux->next)
			while (aux->next)
				aux = aux->next;
		aux->next = new;	
	}	
}

t_env_lst	*new_lst(char **variables)
{
	int	i;
	t_env_lst *lst;

	i = -1;
	while (variables[++i])
		lst_add_back(&lst ,lst_new(variables[i]));
	return (lst);	
}