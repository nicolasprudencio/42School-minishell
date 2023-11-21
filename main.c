/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:19:41 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/21 18:52:55 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

int	main(void)
{
	t_list	*lexer;
	t_list	*aux;

	lexer = NULL;
	create_lexer("testecd234pwdmaisumexport", &lexer);
	aux = lexer;
	while (aux)
	{
		printf("%s\n", ((t_token *)(aux->content))->name);
		printf("%d\n", ((t_token *)(aux->content))->type);
		aux = aux->next;
	}
	return (0);
}
