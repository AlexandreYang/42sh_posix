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

#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

void				ast_if_then_del(t_ast_if_then *this)
{
	if (this->cond_compound)
		ast_compound_list_del(this->cond_compound);
	if (this->then_compound)
		ast_compound_list_del(this->then_compound);
	free(this);
}
