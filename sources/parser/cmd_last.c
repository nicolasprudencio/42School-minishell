/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_cmd_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:23:47 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:23:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	cmd_last(t_cmd_table **last, t_cmd_table **cmd_table)
{
	*last = *cmd_table;
	while (*last && (*last)->next)
	{
		(*last)->next->prev = (*last);
		*last = (*last)->next;
	}
}
