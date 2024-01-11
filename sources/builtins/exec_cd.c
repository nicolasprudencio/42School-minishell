/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:21:36 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/11 17:49:56 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	update_pwd(t_env_lst **lst, char *new_path)
{
	t_env_lst *aux;
	
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

void	update_oldpwd(t_env_lst **lst, char *old_path)
{
	t_env_lst *aux;
	
	aux = *lst;
	while (aux)
	{
		if (str_ncmp(aux->value, "OLDPWD", str_len("OLDPWD")) == 0)
		{
			free(aux->value);
			aux->value = str_join("OLDPWD=",old_path, 0);
			return ;
		}
		aux = aux->next;	
	}
}

int	exec_cd(char *dir, t_env_lst **lst)
{
	char	*path;
	char	buffer[1024];
	
	printf("%s\n", buffer);
	if (getcwd(buffer, sizeof(buffer)) != NULL)
	{	
		update_oldpwd(lst, buffer);
		path = str_join(buffer, "/", 0);
		path = str_join(path, dir, 1);
		update_pwd(lst, path);
		chdir(path);
		free(path);
		return (TRUE);
	}
	return (FALSE);
}