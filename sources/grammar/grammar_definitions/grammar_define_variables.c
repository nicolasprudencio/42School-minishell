/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_define_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:48:54 by nprudenc          #+#    #+#             */
/*   Updated: 2023/12/05 19:11:56 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	**grammar_define_variables()
{
	char	**variables;

	variables = (char **)mem_calloc(2, sizeof(char *));
	variables[0] = str_dup("n");
	return (variables);
}