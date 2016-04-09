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

#include "expan/expansion.h"

static void		iter_fn(void *data, void *next, void *context)
{
	t_expansion	*this;

	this = context;
	if (!this->to_push_bs)
		this->to_push_bs = data;
	else
		twl_lst_cat(this->to_push_bs, data);
	if (next)
	{
		twl_lst_push_back(this->before_split, this->to_push_bs);
		this->to_push_bs = NULL;
	}
}

void			expansion_push_lst_before_split(t_expansion *this, t_lst *lst)
{
	twl_lst_itern(lst, iter_fn, this);
}
