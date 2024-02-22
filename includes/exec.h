/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:42:41 by fpolaris          #+#    #+#             */
/*   Updated: 2024/02/21 10:43:09 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libseas.h"

int	exec(t_cmd_table **cmd_table, t_pushdown_automaton *parse_bot);
int	exec_open_process(t_cmd_table **cmd, t_pushdown_automaton *parse_bot);

// builtins

int	exec_cd(char *dir, t_llist **lst);
int	exec_echo(char **str, int fd);
int	exec_env(t_llist *lst, int fd);
int	exec_export(t_llist *env, t_command *cmd);
int	exec_unset(t_llist **env, char **cmd);
int	get_pwd(int fd);
int	exec_exit(t_pushdown_automaton *parse_bot, t_cmd_table *cmd);

#endif
