/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:28:21 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/21 22:35:22 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	*var_exists(t_llist *lst, char *var)
{	
	t_llist	*aux;

	aux = lst;
	while (aux)
	{
		if (is_valid_env(aux->value, &var[1], '='))
			return (aux->value);
		aux = aux->next;
	}
	return (NULL);
}
