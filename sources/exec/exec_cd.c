/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:21:36 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/21 10:37:43 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_update_pwd(t_llist **ll, char *new_path)
{
	t_llist *aux;
	
	aux = *ll;
	while (aux)
	{
		if (str_ncmp(aux->value, "PWD", str_len("PWD")) == 0)
		{
			free(aux->value);
			aux->value = str_join("PWD=", new_path, 0);
			return ;
		}
		aux = aux->next;
	}
}

static void	st_update_oldpwd(t_llist **ll, char *old_path)
{
	t_llist *aux;
	
	aux = *ll;
	while (aux)
	{
		if (str_ncmp(aux->value, "OLDPWD", str_len("OLDPWD")) == 0)
		{
			free(aux->value);
			aux->value = str_join("OLDPWD=", old_path, 0);
			return ;
		}
		aux = aux->next;	
	}
}

int	exec_cd(char *dir, t_llist **env)
{
	char	buffer[1024];
	
	getcwd(buffer, sizeof(buffer));
	if (chdir(dir) != FALSE_INDEX)
	{	
		st_update_oldpwd(env, buffer);
		getcwd(buffer, sizeof(buffer));
		st_update_pwd(env, buffer);
		return (0);
	}
	else
		printf("SEAshell: cd: %s: No such file or directory\n", dir);
	return (1);
}
