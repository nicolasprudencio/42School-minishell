/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/10 17:10:18 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_export(t_env_lst *lst, char *var, int fd)
{
	t_env_lst	*aux;

	if (var)
	{
		lst_add_back(&lst, lst_new(var));
		return (TRUE);
	}
	aux = lst;
	while (aux)
	{	
		put_str("declare -x ", fd);
		put_endl(aux->value, fd);
		aux = aux->next;
	}
	return (TRUE);
}