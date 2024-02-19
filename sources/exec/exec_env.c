/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:49:27 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/25 17:35:59 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_env(t_llist *llist, int fd)
{	
	t_llist	*aux;

	aux = llist;
	while (aux)
	{
		if (char_exists(aux->value, '='))
			put_endl(aux->value, fd);
		aux = aux->next;
	}
	return (0);
}
