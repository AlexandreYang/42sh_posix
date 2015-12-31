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

#include "ast/nodes/ast_if_clause.h"

void				ast_if_clause_print_rec(t_ast_if_clause *ast_if_clause, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_if_clause\n");
	depth++;
	token_mgr_print(ast_if_clause->tokens);
	(void)ast_if_clause;
}