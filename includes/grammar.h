/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:43:31 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 10:43:33 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

t_dictionary	*grammar_new(void);
void			grammar_end(t_dictionary *seas_script);

char			**grammar_define_terminals(void);
void			grammar_free_terminals(char **terminals);

t_production	*grammar_define_productions(void);
void			grammar_free_productions(t_production *product);

char			**grammar_define_variables(void);
void			grammar_free_variables(char **variables);

#endif
