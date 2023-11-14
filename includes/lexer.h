/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:55:34 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/14 17:41:03 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H


# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif

// typedef enum e_tokens {
// 	PIPE = 2,
// 	ECHO,
// 	CD,
// 	PWD,
// 	EXPORT,
// 	UNSET,
// 	ENV,
// 	EXIT,
// }			t_tokens;

/*
	LEXER TYPE STRUCT

	0 - TERMINAL
	1 - VARIABLE
*/

typedef struct	s_token {
	char	*name;
	int		type;
}				t_token;

#endif


char	*is_token(char *str);