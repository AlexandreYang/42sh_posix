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

#include <stdlib.h>

#include "ast/ast.h"

#include "ast/nodes/ast_node.h"
#include "ast/nodes/ast_if_clause.h"
#include "ast/nodes/ast_cmd_field.h"
#include "ast/nodes/ast_pipe_seq.h"
#include "ast/nodes/ast_andor_seq.h"
#include "ast/nodes/ast_cmd_sub.h"

char				*ast_str(t_ast *ast)
{
	char			*out;
	// ast_str_append_list(ast, ast->root);
	ast_str_append2_complete_command(ast, ast->complete_command);
	out = twl_lst_strjoin(ast->out_lines, "");
	return (out);
}
