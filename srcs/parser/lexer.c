/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:26:50 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/10 15:04:56 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

static int	st_is_redirect(char *str, int index)
{	
	char	r1;
	char	r2;
	
	r1 = '<';
	r2 = '>';
	if (str[index] == r1 && str[index + 1] != r1 || str[index] == r2 && str[index + 1] != r2)
		return (TRUE);
	return (FALSE);	
}

static int	st_is_terminal(char *str)
{
	if (!ft_isalpha(str[0]))
		return (FALSE);
	else if (ft_strncmp(str, "echo", 4))
		return (ECHO);	
	else if (ft_strncmp(str, "cd", 2))
		return (CD);
	else if (ft_strncmp(str, "pwd", 3))
		return (PWD);
	else if (ft_strncmp(str, "export", 6))
		return (EXPORT);
	else if (ft_strncmp(str, "unset", 5))
		return (UNSET);
	else if (ft_strncmp(str, "env", 3))
		return (ENV);
	else if (ft_strncmp(str, "exit", 4))
		return (EXIT);
	return (FALSE);
}

