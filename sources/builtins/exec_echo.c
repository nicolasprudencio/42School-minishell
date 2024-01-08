/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:34:33 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/08 17:41:20 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	exec_echo(int fd, char *str, int flag)
{
	if (flag == FALSE)
	{
		put_str(str, fd);
		put_char('\n', fd);
		return (TRUE);
	}
	put_str(str, fd);
	return (TRUE);
}