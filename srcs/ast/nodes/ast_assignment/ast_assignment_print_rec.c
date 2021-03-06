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

#include "ast/nodes/ast_assignment.h"

void				ast_assignment_print_rec(t_ast_assignment *ast_assignment,
	int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_assignment (%s=%s)\n",
		ast_assignment->key, ast_assignment->value
			? ast_assignment->value : "");
	depth++;
	(void)ast_assignment;
}
