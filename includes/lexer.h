/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:55:34 by nicolas           #+#    #+#             */
/*   Updated: 2023/11/10 00:02:36 by nicolas          ###   ########.fr       */
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

/*
	LEXER TYPE STRUCT

	0 - TERMINAL
	1 - VARIABLE
*/

typedef struct	s_lexer {
	char	*name;
	int		type;
	struct s_lexer *next;
}				t_lexer;

#endif
