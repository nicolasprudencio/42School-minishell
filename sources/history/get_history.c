/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:46:18 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/05 19:09:03 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static char	*st_get_user(char *path)
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

static char	*st_get_history_path()
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

void	get_history()
{
	char	*history_file;
	char	*line;
	int		fd;
	
	history_file = get_history_path();
	fd = open(history_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		put_str(line, 1);
		free(line);
	}
	close(fd);
	free(history_file);
	free(line);
}