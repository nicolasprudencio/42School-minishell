/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_cmd_iredir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:22:59 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:23:00 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_try_to_access(t_cmd_table **last, char *path);

int	cmd_iredir(t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	*last;
	char		*path;

	path = token->value;
	cmd_last(&last, cmd_table);
	st_try_to_access(&last, path);
	if (last->command->io[STDIN_FILENO] != STDIN_FILENO
		&& last->command->io[STDIN_FILENO] != FD_HEREDOC)
		close(last->command->io[STDIN_FILENO]);
	last->command->io[STDIN_FILENO] = open(path, O_RDONLY);
	if (!last->command->io[STDIN_FILENO])
	{
		printf("SEAshell: %s: Failed to open\n", path);
		return (FALSE);
	}
	return (TRUE);
}

static void	st_try_to_access(t_cmd_table **last, char *path)
{
	if (access(path, F_OK) == FALSE_INDEX)
	{
		printf("SEAshell: %s: No such file or directory\n", path);
		free((*last)->command->parsed[0]);
		(*last)->command->parsed[0] = str_dup("(Invalid)");
	}
	else if (access(path, R_OK) == FALSE_INDEX)
	{
		printf("SEAshell: %s: Permission denied\n", path);
		free((*last)->command->parsed[0]);
		(*last)->command->parsed[0] = str_dup("(Invalid)");
	}
}
