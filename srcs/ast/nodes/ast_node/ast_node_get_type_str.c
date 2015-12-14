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

#include "ast/nodes/ast_node.h"

char				*ast_node_get_type_str(void *ast_node)
{
	if (ast_node_get_type(ast_node) == AST_COMPOUND)
		return ("AST_COMPOUND");
	else if (ast_node_get_type(ast_node) == AST_IF)
		return ("AST_IF");
	else if (ast_node_get_type(ast_node) == AST_CMD)
		return ("AST_CMD");
	else if (ast_node_get_type(ast_node) == AST_CMD_FIELD)
		return ("AST_CMD_FIELD");
	else if (ast_node_get_type(ast_node) == AST_PIPE)
		return ("AST_PIPE");
	else if (ast_node_get_type(ast_node) == AST_ANDOR)
		return ("AST_ANDOR");
	return ("NOT_FOUND");
}
