/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:49:27 by nicolas           #+#    #+#             */
/*   Updated: 2024/01/08 19:41:44 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

/*
	It will be necessary to treat when env variables are defined lik YYY
	and use de char **env option to create a linked list with all env variables and the new ones.

*/

void	exec_env()
{	
	char	**env;
	int		i;

	env = __environ;
	i = -1;
	
	while (env[++i])
		printf("%s\n", env[i]);
}
