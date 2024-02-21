/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:48:09 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 10:48:10 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_prodution
{
	char	*variable;
	char	**output;
}	t_production;

typedef struct s_dictionary
{
	char			**variables;
	char			**terminals;
	t_production	*production;
	char			*start;
}	t_dictionary;

typedef struct s_token
{
	char			*token_type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_command
{
	char	**parsed;
	int		io[2];
}	t_command;

typedef struct s_cmd_table
{
	t_command			*command;
	struct s_cmd_table	*next;
	struct s_cmd_table	*prev;
}	t_cmd_table;

typedef struct s_relation
{
	char	*input;
	char	*stack_top;
}	t_relation;

typedef struct s_pushdown_automaton
{
	int				current_state;
	t_relation		*transition;
	int				starting_state;
	char			*initial_symbol;
	t_stack			*stack;
	t_dictionary	*language;
	t_llist			*env_list;
}	t_pushdown_automaton;

#endif
