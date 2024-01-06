/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:46:18 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/06 14:11:12 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	get_history()
{
	char	*history_file;
	char	*line;
	int		fd;
	
	history_file = get_history_path();
	fd = open(history_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error when opening file!");
		return (FALSE);
	}
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
	return (TRUE);
}