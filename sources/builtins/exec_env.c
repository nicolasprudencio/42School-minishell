/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:49:27 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/10 13:31:03 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

/*
	It will be necessary to treat when env variables are defined lik YYY
	and use de char **env option to create a linked list with all env variables and the new ones.

*/

void	exec_env(t_env_lst *lst)
{	
	t_env_lst	*aux;
	int			i;

	i = -1;
	aux = lst;
	while (aux->next)
		if (str_find_char(aux->value, '=', 0))
		{
			printf("%s\n", aux->value);
			aux = aux->next;
		}
}
