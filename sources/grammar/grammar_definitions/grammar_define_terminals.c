/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_define_terminals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:49:04 by nprudenc          #+#    #+#             */
/*   Updated: 2023/11/29 19:09:25 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfpp.h"

char	**grammar_define_terminals()
{
	char	**terminals;
	
	terminals = (char **)mem_calloc(2, sizeof(char *));
	terminals[0] = "echo";
	return (terminals);

}

int main(void)
{
	fp_printf("terminals: %s\n", **grammar_define_terminals());
	return (0);
}