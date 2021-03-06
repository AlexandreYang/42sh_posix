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

#include "ast/nodes/ast_andor_item.h"

static void			iter_fn(void *ast_pipe_item, void *depth_ptr)
{
	ast_pipe_item_print_rec(ast_pipe_item, *(int *)depth_ptr);
}

void				ast_andor_item_print_rec(t_ast_andor_item *this, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_andor_item (negate=%s, sep=%s)",
		this->negate ? "true" : "false",
		this->separator ? this->separator->text : "none");
	twl_putstr("\n");
	depth++;
	twl_lst_iter(this->ast_pipe_items, iter_fn, &depth);
}
