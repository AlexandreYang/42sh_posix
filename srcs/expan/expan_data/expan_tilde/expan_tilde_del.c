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

#include "expan/expan_tilde.h"

void			expan_tilde_del(void *expan_tilde_)
{
	t_expan_tilde *expan_tilde;

	expan_tilde = expan_tilde_;
	twl_strdel(&expan_tilde->token);
	twl_strdel(&expan_tilde->suffix);
	free(expan_tilde);
}