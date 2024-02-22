/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:05:16 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/21 10:40:38 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	get_pwd(int fd)
{
	char	buf[1024];

	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		put_endl(buf, fd);
		return (0);
	}
	return (0);
}
