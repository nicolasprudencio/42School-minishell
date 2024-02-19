/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:14 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/16 16:58:50 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_unset(t_llist **env, char **cmd)
{
	int	argument_count;

	argument_count = grid_len(cmd);
	while (--argument_count != FALSE_INDEX)
		ll_remove_node(env, cmd[argument_count]);
	return (0);
}
