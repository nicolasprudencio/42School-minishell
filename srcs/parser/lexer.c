/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:26:50 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/15 13:28:25 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

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

static void	st_define_token_type(t_token *token)
{
		int	i;
	char	*terminals[13] = {"|", "echo", "cd", "pwd", "export", "unset", "env", "exit", "<", ">", "<<", ">>", "\0"};

	i = -1;
	while (++i < 12)
		if (!ft_strncmp(token->name, terminals[i], ft_strlen(terminals[i])))
			token->type = TERMINAL;
}

void	create_lexer(char	**argv, t_list **lexer)
{	
	int	i;
	int	j;
	t_token	*token;
	t_list	*new_token;
	char	*token_name;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			token_name = is_token(&argv[i][j]);
			if (token_name)
			{	
				token = ft_calloc(1, sizeof(t_token *));
				new_token = ft_lstnew(token);
				((t_token *)(new_token->content))->name = token_name;
				st_define_token_type((t_token *)(new_token->content));
				ft_lstadd_back(lexer, new_token);
			}
		}
	}
}
