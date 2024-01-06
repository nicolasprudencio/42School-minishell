/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:07:09 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/06 14:08:35 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	*get_user(char *path)
{
	char	*user;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (path[++i])
	{
		if (path[i] == '/')
			j++;
		if (j == 3)
			break ;	
	}
	user = str_ndup(path, i + 1);
	free(path);
	return (user);
}

char	*get_history_path()
{
	char	*buffer;
	char	*user;

	buffer = mem_calloc(1024, sizeof(char));
	if (getcwd(buffer, 1024))
	{
		user = st_get_user(buffer);
		user = str_join(user, ".bash_history", 1);
		return (buffer);
	}
	return (NULL);
}
