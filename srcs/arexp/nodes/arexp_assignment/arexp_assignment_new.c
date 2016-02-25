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

#include "arexp/nodes/arexp_assignment.h"

t_arexp_assignment		*arexp_assignment_new(void)
{
	t_arexp_assignment	*arexp_assignment;

	arexp_assignment = twl_malloc_x0(sizeof(t_arexp_assignment));
	arexp_assignment->lst_assign = twl_lst_new();
	return (arexp_assignment);
}
