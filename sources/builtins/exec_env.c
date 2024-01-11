/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:49:27 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/11 20:09:03 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	exec_env(t_env_lst *lst, int fd)
{	
	t_env_lst	*aux;
	int			i;

	i = -1;
	aux = lst;
	while (aux)
	{
		if (str_find_char(aux->value, '=', 0))
			put_endl(aux->value, fd);
		aux = aux->next;
	}
}
