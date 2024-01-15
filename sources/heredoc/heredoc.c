/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:43:53 by nprudenc          #+#    #+#             */
/*   Updated: 2024/01/15 19:58:36 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

void	here_doc(t_env_lst *lst, char *eof, int fd)
{
	char		*line;
	char		*env_var;
	t_env_lst	*aux;

	while (1)
	{
		aux = lst;
		line = readline("> ");
		// if (str_len_until(line, '$') != FALSE_INDEX)
		// 	find_var_value(line, lst);
		env_var = env_expand_variables(line, lst);
		if (env_var)
		{
			put_str(env_var, fd);
			free(env_var);
		}
		else	
			put_str(line, fd);
		put_str("\n", fd);
		if (str_comp(line, eof) == 0)
		{
			free(line);
			return ;
		}
		free(line);
	}
}