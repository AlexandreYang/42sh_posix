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

static void		strlen_from_new_line(t_expansion *this, char *text)
{
	while (*text)
	{
		if (*text == '\n' || *text == '\r')
			this->size_prompt = 0;
		else
			this->size_prompt += 1;
		text += 1;
	}
}

void			expansion_push_before_split(t_expansion *this,
											char *text,
											bool quoted)
{
	t_expan_before_split	*ebs;

	if (!text)
		return ;
	ebs = expan_before_split_new(text, quoted);
	if (this->flag_prompt && !this->flag_prompt_open_close)
		strlen_from_new_line(this, text);
	if (!this->to_push_bs)
		this->to_push_bs = twl_lst_new();
	twl_lst_push_back(this->to_push_bs, ebs);
}
