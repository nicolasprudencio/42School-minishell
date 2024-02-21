/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:24 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/24 13:57:40 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

int	main(int argc, char **argv, char **envp)
{
	t_pushdown_automaton	*parse_bot;

	if (argc != 1)
		return (FALSE);
	(void)argv;
	parse_bot = automaton_new(envp);
	while (1)
	{
		if (!core(parse_bot, "SEAshell~ ", STDIN_FILENO))
			break ;
	}
	automaton_destroy(parse_bot);
}
