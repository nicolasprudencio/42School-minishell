/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:13:58 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 11:13:59 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_dictionary	*grammar_new(void)
{
	t_dictionary	*seas_script;

	seas_script = (t_dictionary *)mem_calloc(1,
			sizeof(t_dictionary));
	seas_script->variables = grammar_define_variables();
	seas_script->terminals = grammar_define_terminals();
	seas_script->production = grammar_define_productions();
	seas_script->start = "<COMMAND>";
	return (seas_script);
}

void	grammar_end(t_dictionary *seas_script)
{
	grammar_free_variables(seas_script->variables);
	grammar_free_productions(seas_script->production);
	grammar_free_terminals(seas_script->terminals);
	free(seas_script);
}
