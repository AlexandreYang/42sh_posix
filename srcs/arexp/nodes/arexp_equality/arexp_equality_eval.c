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

#include "arexp/arexp.h"
#include "arexp/nodes/arexp_equality.h"

static void		fn_iter(void *data, void *prev, void *ret)
{
	long long			tmp;

	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	tmp = arexp_relational_eval(((t_arexp_equality__ *)data)->relational);
	if (!prev)
		*((long long *)ret) = tmp;
	else if (((t_arexp_equality__ *)prev)->equality_sign->type ==
																TOK_AREXP_EQUAL)
		*((long long *)ret) = (*((long long *)ret) == tmp);
	else
		*((long long *)ret) = (*((long long *)ret) != tmp);
}

long long		arexp_equality_eval(t_arexp_equality *this)
{
	long long	ret;

	twl_lst_iterp(this->relational, fn_iter, &ret);
	return (ret);
}
