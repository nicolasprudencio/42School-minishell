/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:34:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/02/16 17:12:47 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	st_is_flag(char *str);

int	exec_echo(char **str, int fd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (str[i])
	{
		if (st_is_flag(str[i]))
		{
			flag = 1;
			i++;
		}
		else
			break;
	}
	while (str[i])
	{
		put_str(str[i], fd);
		if (str[++i])
			put_char(' ', fd);
	}
	if (!flag)
		put_endl("", fd);
	return (0);
}

static int	st_is_flag(char *str)
{
	int	i;

	i = -1;
	if (str[++i] == '-')
	{
		while (str[++i])
		{
			if (str[i] != 'n')
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
