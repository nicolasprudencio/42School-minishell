/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_cmd_append.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:21:43 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:21:44 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	cmd_append(t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;
	char		*path;

	path = token->value;
	cmd_last(&last, cmd_table);
	if (access(path, F_OK == FALSE_INDEX))
		open(path, O_CREAT);
	if (access(path, W_OK) == FALSE_INDEX)
	{
		printf("SEAshell: %s: Permission denied\n", path);
		return (FALSE);
	}
	if (last->command->io[STDOUT_FILENO] != STDOUT_FILENO)
		close(last->command->io[STDIN_FILENO]);
	last->command->io[STDOUT_FILENO] = open(path, O_WRONLY | O_APPEND);
	if (!last->command->io[STDOUT_FILENO])
	{
		printf("SEAshell: %s: Failed to open\n", path);
		return (FALSE);
	}
	return (TRUE);
}
