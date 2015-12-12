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

#include <stdlib.h>

#include "pattern.h"

static void			del_pattern_data(void *data_)
{
	t_pattern_data	*data;

	data = data_;
	free(data->split);
	free(data);
}

void				pattern_del(t_pattern *this)
{
	twl_lst_del(this->split, del_pattern_data);
	free(this->pattern);
	free(this);
}
