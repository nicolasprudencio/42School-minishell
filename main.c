/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:19:41 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/15 12:57:09 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

int	main(int argc, char **argv)
{
	t_list	*lexer;
	t_list	*aux;

	lexer = NULL;
	if (argc <= 1)
		return (1);
	create_lexer(argv, &lexer);
	aux = lexer;
	while (aux)
	{
		printf("%s\n", ((t_token *)(aux->content))->name);
		aux = aux->next;
	}
	return (0);
}
