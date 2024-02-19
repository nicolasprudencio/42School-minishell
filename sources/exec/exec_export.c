/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/16 16:58:17 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_put_env(t_llist *env, int fd);
static void	st_add_to_list(t_llist **env, char **values);

int	exec_export(t_llist *env, t_command *cmd)
{
	int		argument_count;

	argument_count = grid_len(cmd->parsed);
	if (argument_count == 1)
		st_put_env(env, cmd->io[STDOUT_FILENO]);
	else
		st_add_to_list(&env, &cmd->parsed[1]);
	return (TRUE);
}

static void	st_add_to_list(t_llist **env, char **values)
{
	int		i;
	t_llist	*aux;

	aux = *env;
	while (aux)
	{
		i = -1;
		while (values[++i])
		{
			if (!str_comp_upto(aux->value, values[i], '='))
			{
				free(aux->value);
				aux->value = str_dup(values[i]);
			}
			else
				ll_add_back(env, ll_node(values[i]));
		}
		aux = aux->next;
	}
}

static void	st_put_env(t_llist *env, int fd)
{
	t_llist	*aux;

	aux = env;
	while (aux)
	{	
		put_str("declare -x ", fd);
		put_str(aux->value, fd);
		if (aux->value[str_len_until(aux->value, '=') + 1] == '\0')
			put_str("\"\"", fd);
		put_str("\n", fd);	
		aux = aux->next;
	}
}
