/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:14:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/20 20:44:04 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_put_env(t_llist *env, int fd);
static int	st_add_to_list(t_llist **env, char **values);

int	exec_export(t_llist *env, t_command *cmd)
{
	int		argument_count;

	argument_count = grid_len(cmd->parsed);
	if (argument_count == 1)
	{
		if (!st_put_env(env, cmd->io[STDOUT_FILENO]))
			return (1);
	}
	else
	{
		if (!st_add_to_list(&env, &cmd->parsed[1]))
			return (1);
	}
	return (0);
}

static int	st_already_exists(t_llist **env, char *value, int *has_added)
{
	t_llist	*aux;

	aux = *env;
	while (aux)
	{
		if (!str_comp_upto(aux->value, value, '='))
		{
			free(aux->value);
			aux->value = str_dup(value);
			*has_added = 1;
			return (TRUE);
		}
		aux = aux->next;
	}
	return (FALSE);
}

static int	st_add_to_list(t_llist **env, char **values)
{
	int		i;
	int		has_added;

	i = -1;
	while (values[++i])
	{	
		if (is_digit(values[i][0]))
		{
			printf("SEAshell: export: `%s': not a valid identifier\n",
				values[i]);
			return (FALSE);
		}
		has_added = 0;
		if (st_already_exists(env, values[i], &has_added))
			break ;
		if (!has_added)
		{	
			ll_add_back(env, ll_node(values[i]));
			has_added = 1;
		}
	}
	return (TRUE);
}

static int	st_put_env(t_llist *env, int fd)
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
	return (TRUE);
}
