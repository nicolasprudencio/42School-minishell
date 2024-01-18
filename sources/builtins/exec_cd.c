/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:21:36 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/16 15:36:24 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static void	st_update_pwd(t_lst **lst, char *new_path)
{
	t_lst *aux;
	
	aux = *lst;
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

static void	st_update_oldpwd(t_lst **lst, char *old_path)
{
	t_lst *aux;
	
	aux = *lst;
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

int	exec_cd(char *dir, t_lst **lst)
{
	char	buffer[1024];
	
	if (getcwd(buffer, sizeof(buffer)) != NULL)
	{	
		st_update_oldpwd(lst, buffer);
		chdir(dir);
		getcwd(buffer, sizeof(buffer));
		st_update_pwd(lst, buffer);
		return (TRUE);
	}
	return (FALSE);
}
