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

#include "twl_xstdlib.h"

#include "ast/nodes/ast_cmd_subshell.h"

t_ast_cmd_subshell	*ast_cmd_subshell_new(void)
{
	t_ast_cmd_subshell	*this;

	this = twl_malloc_x0(sizeof(t_ast_cmd_subshell));
	this->type = AST_CMD_SUBSHELL;
	this->list = NULL;
	this->index = 0;
	return (this);
}
