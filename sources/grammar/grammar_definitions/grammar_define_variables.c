/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_define_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:48:54 by nprudenc          #+#    #+#             */
/*   Updated: 2023/11/29 18:49:15 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

char	**grammar_define_variables()
{
	char	**output;

	output = str_split("<COMMAND> <ARGUMENT> <FLAG> <TERMINAL> <STRING>",
			' ');
	return (output);
}
