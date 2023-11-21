/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:19:41 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/21 20:20:08 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

int	main(void)
{
	t_token	*lexer;
	t_token	*aux;

	lexer = NULL;
	create_lexer("basictestcd2>>pwdmaisumexport", &lexer);
	aux = lexer;
	while (aux)
	{
		printf("%s\n", aux->name);
		printf("%d\n", aux->type);
		aux = aux->next;
	}
	return (0);
}
