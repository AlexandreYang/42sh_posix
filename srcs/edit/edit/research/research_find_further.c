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

#include "edit/research.h"

static void		iter_fn(void *data, void *context)
{
	t_edit		*this;

	this = context;
	if (this->research->found == true)
		return ;
	research_rewind_string(this, data, ((t_line *)data)->size);
	if (this->research->found == true)
	{
		history_set_current(this->history, this->current);
	}
}

void			research_find_further(t_edit *this)
{
	research_clear(this);
	this->research->found = false;
	if (this->pos_cursor != 0)
		research_rewind_string(this, this->current, this->pos_cursor - 1);
	history_iter_from_prev_to_first(this->history, iter_fn, this);
	research_print_prompt(this);
	research_print_line(this);
}
