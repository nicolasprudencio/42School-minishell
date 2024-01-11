/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/11 20:29:17 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int comp_until(char *str1, char *str2, int c)
{
	int	i;

	i = -1;
	while (str1[++i] && str2[i] && str2[i] != c && str1[i] == str2[i])
		;
	if (str1[i] == c && str2[i] == c)
		return (TRUE);
	return (FALSE);	
}

static int	st_to_replace(t_env_lst	**lst, char *var)
{
	t_env_lst *aux;
	t_env_lst *temp;

	aux = *lst;
	temp = *lst;
	while (aux)
	{	
		if (comp_until(aux->value, var, '=') == 1)
		{
			free(aux->value);
			aux->value = str_dup(var);
			// lst_del_one(aux);
			// lst_add_back(lst, lst_new(var));
			return (TRUE);
		}
		aux = aux->next;
	}
	return (FALSE);
}

int	exec_export(t_env_lst *lst, char *var, int fd)
{
	t_env_lst	*aux;

	aux = lst;
	if (var)
	{	
		if (st_to_replace(&lst, var))
			return (TRUE);
		else
			lst_add_back(&lst, lst_new(var));
		return (TRUE);
	}
	while (aux)
	{	
		put_str("declare -x ", fd);
		put_endl(aux->value, fd);
		aux = aux->next;
	}
	return (TRUE);
}