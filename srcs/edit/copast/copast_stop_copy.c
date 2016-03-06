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

#include "edit/copast.h"

void				copast_stop_copy(t_copast *this, int index, t_lst *letters)
{
	t_lst			*slice;
	int				max;
	int				min;

	this->stop_index = index;
	min = this->start_index > this->stop_index ? this->stop_index : this->start_index;
	max = this->start_index > this->stop_index ? this->start_index : this->stop_index;
	slice = twl_lst_slice(letters, min, max);
	this->clip = twl_lst_copy(slice, letter_copy_void);
	free(slice);
	this->inc_index = max - min;
	this->has_copy = true;
}