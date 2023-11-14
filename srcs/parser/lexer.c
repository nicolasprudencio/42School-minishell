/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:26:50 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/14 17:43:12 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

// static int	st_is_redirect(char *str, int index)
// {	
// 	char	r1;
// 	char	r2;
	
// 	r1 = '<';
// 	r2 = '>';
// 	if ((str[index] == r1 && str[index + 1] != r1) || (str[index] == r2 && str[index + 1] != r2))
// 		return (TRUE);
// 	return (FALSE);	
// }

char	*is_token(char *str)
{
	int	i;
	char	*terminals[13] = {"|", "echo", "cd", "pwd", "export", "unset", "env", "exit", "<", ">", "<<", ">>", "\0"};

	i = -1;
	while (++i < 12)
		if (!ft_strncmp(str, terminals[i], ft_strlen(terminals[i])))
			return (ft_strdup(terminals[i]));
	return (NULL);
}

int	lexer(char	**argv)
{	
	int	i;
	int	j;
	t_list	*lexer;
	t_token	*token;
	t_list	*new_token;
	char	*token_name;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			token_name = is_token(&argv[i][j]);
			if (token_name)
			{	
				new_token = ft_lstnew(token);
				(t_token *)(new_token->content)->name = token_name;
				ft_lstadd_back(&lexer, new_token);
			}
		}
	}
}