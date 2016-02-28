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

#include "arexp/arexp_utils.h"
#include "arexp/nodes/arexp_equality.h"
#include "twl_stdio.h"

static void		fn_iter(void *data, void *depth)
{
	t_arexp_equality__	*eq;

	eq = data;
	arexp_print_indent(*((int *)depth));
	if (eq->equality_sign)
		twl_printf("equality %s\n", eq->equality_sign->text);
	else
		twl_printf("equality\n");
	arexp_relational_print_rec(eq->relational, *((int *)depth) + 1);
}

void			arexp_equality_print_rec(t_arexp_equality *this, int depth)
{
	twl_lst_iter(this->relational, fn_iter, &depth);
}
