/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:51:22 by nprudenc          #+#    #+#             */
/*   Updated: 2023/11/30 19:58:19 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

t_dictionary	*grammar_new()
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
