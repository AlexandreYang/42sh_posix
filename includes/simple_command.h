/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_COMMAND_H
# define SIMPLE_COMMAND_H

# include "basics.h"
# include "ast/ast.h"
# include "twl_arr.h"

typedef struct				s_simple_command
{
	t_dict				*builtin_func;
}						t_simple_command;

t_simple_command		*simple_command_new(void);
void					simple_command_del(t_simple_command *sc);
void					travel_simple_command(void *ast_node,  void *cmd);
void					simple_command_entrance(t_simple_command *cmd, t_ast *this);
void					travel_ast_cmd(t_simple_command *cmd, void *ast_node);
char					*concatenate_ast_cmd(t_lst *ast_nodes);
bool					is_builtin(char *cmd);
char					*get_binary_path(char *cmd);

#endif
