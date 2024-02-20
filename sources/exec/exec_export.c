/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/20 19:41:59 by nicolas          ###   ########.fr       */
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
	int		has_added;
	t_llist	*aux;

	i = -1;
	while (values[++i])
	{
		aux = *env;
		has_added = 0;
		while (aux)
		{
			if (!str_comp_upto(aux->value, values[i], '='))
			{
				free(aux->value);
				aux->value = str_dup(values[i]);
				has_added = 1;
				break ;
			}
			aux = aux->next;
		}
		if (!has_added)
		{
			ll_add_back(env, ll_node(values[i]));
			has_added = 1;
		}
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
