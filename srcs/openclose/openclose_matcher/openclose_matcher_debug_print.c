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

#include "openclose/openclose_matcher.h"

static void			print_openclose_fn(void *openclose_)
{
	t_openclose	*openclose;

	openclose = openclose_;
	twl_lprintf("%s - %s\n", openclose->open, openclose->close);
}

void				openclose_matcher_debug_print(t_openclose_matcher *matcher)
{
	twl_lprintf("%s>>>>>>>>>> openclose list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(matcher->oc_pairs, print_openclose_fn);
	twl_lprintf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
