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

#include "ast/anode/if_stmt.h"

t_if_stmt			*if_stmt_new(void)
{
	t_if_stmt	*this;

	this = twl_malloc_x0(sizeof(t_if_stmt));
	this->type = IF_STMT;
	this->cond = compound_stmt_new();
	this->body = compound_stmt_new();
	this->elze = compound_stmt_new();
	return (this);
}