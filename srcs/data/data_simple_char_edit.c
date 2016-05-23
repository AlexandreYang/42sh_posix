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

#include "data.h"
#include "edit/edit.h"
#include "edit/simple_char.h"

t_lst				*data_simple_char_edit(void)
{
	static t_lst	*data = NULL;

	if (!data)
	{
		data = twl_lst_new();
		twl_lst_push_front(data, simple_char_new('\001', edit_move_home));
		twl_lst_push_front(data, simple_char_new('\005', edit_move_end));
		twl_lst_push_front(data, simple_char_new('\004', edit_del_right));
		twl_lst_push_front(data, simple_char_new('\177', edit_del_left));
		twl_lst_push_front(data, simple_char_new('\013', edit_del_all_right));
	}
	return (data);
}
