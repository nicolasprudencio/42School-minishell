/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:24 by nprudenc          #+#    #+#             */
/*   Updated: 2023/11/30 19:46:04 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	main(void)
{
	char	*rl_output;
	char	**terminal;

	terminal = grammar_define_terminals();
	fp_printf("terminals = %s\n", terminal[0]);
	while (1)
	{
		rl_output = readline("SEAshell~ ");
		if (!str_comp(rl_output, "exit"))
		{
			free(rl_output);
			return (0);
		}
		free(rl_output);
	}
	return (0);
}
