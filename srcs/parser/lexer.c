/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:26:50 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/21 20:18:39 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

char	*is_token(char *cmd)
{
	int	i;
	char	*terminals[13] = {"|", "echo", "cd", "pwd", "export", "unset", "env", "exit", "<", ">", "<<", ">>", "\0"};

	i = -1;
	while (++i < 12)
		if (!ft_strncmp(cmd, terminals[i], ft_strlen(terminals[i])))
			return (ft_strdup(terminals[i]));
	return (NULL);
}

static void	st_lexer_add_token(t_token **lexer, t_token *new_token)
{
	t_token	*temp;

	if (!*lexer)
		*lexer = new_token;
	else
	{
		temp = *lexer;
		while (temp->next)
			temp = temp->next;
		temp->next = new_token;	
	}	
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

void	create_lexer(char	*cmd_line, t_token **lexer)
{	
	int	i;
	t_token	*token;
	char	*token_name;

	i = -1;	
	while (cmd_line[++i])
	{
		token_name = is_token(&cmd_line[i]);
		if (token_name)
		{
			token = ft_calloc(1, sizeof(t_token *));
			token->name = token_name;
			st_define_token_type(token);
			st_lexer_add_token(lexer, token);
		}
		token_name = NULL;
	}
}
