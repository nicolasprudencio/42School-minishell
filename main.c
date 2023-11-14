/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:19:41 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/14 16:19:49 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	if (argc <= 1)
		return (1);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			ft_printf("%s\n", is_terminal(&argv[i][j]));
	}
	return (0);
}