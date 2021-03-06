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

void			research_end(t_edit *this)
{
	int			tmp_pos_cursor;

	if (!this->research_mode)
		return ;
	this->research_mode = false;
	research_clear(this);
	research_del(this->research);
	this->research = NULL;
	edit_prompt_print_last_line(this);
	tmp_pos_cursor = this->pos_cursor;
	this->puts(this->current->line);
	this->pos_cursor = this->current->size;
	edit_move_goto_pos_cursor(this, tmp_pos_cursor);
}
