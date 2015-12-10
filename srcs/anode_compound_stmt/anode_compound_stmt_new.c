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

#include "anode_compound_stmt.h"

t_anode_compound_stmt			*anode_compound_stmt_new(void)
{
	t_anode_compound_stmt		*this;

	this = twl_malloc_x0(sizeof(t_anode_compound_stmt));
	this->items = twl_lst_new();
	return (this);
}
