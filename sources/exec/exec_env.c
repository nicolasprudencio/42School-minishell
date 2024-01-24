/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:49:27 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/24 13:14:30 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	exec_env(t_lst *llist, int fd)
{	
	t_lst	*aux;
	int			i;

	i = -1;
	aux = llist;
	while (aux)
	{
		if (char_exists(aux->value, '='))
			put_endl(aux->value, fd);
		aux = aux->next;
	}
}
