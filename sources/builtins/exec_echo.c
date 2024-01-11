/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:34:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/11 13:05:16 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_echo(char **str, int flag, int fd)
{
	int			i;
	// t_env_lst	*aux;

	// if (aux)
	// 	while (aux)
	// 	{	
	// 		if (str_ncmp())
	// 		aux = aux->next;
	// 	}
	i = -1;
	while (str[++i])
		if (flag == FALSE)
			put_endl(str[i], fd);
		else
			put_str(str[i], fd);
	return (TRUE);
}