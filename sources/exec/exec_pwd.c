/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:05:16 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/11 16:10:02 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	get_pwd()
{
	char	buf[1024];

	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		printf("%s\n", buf);
		return (TRUE);
	}
	return (FALSE);
}
