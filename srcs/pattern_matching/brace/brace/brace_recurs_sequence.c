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

#include "pattern_matching/brace/brace.h"

void			brace_recurs_sequence(t_brace *this, t_lst_elem__ *elem,
										t_brace_token *token, char *acc)
{
	t_lst		*copy;
	char		*content;

	copy = twl_lst_copy(token->brace_list, NULL);
	while ((content = twl_lst_pop_front(copy)))
	{
		content = twl_strjoin(acc, content);
		brace_recurs(this, elem->next, content);
		free(content);
	}
	twl_lst_del(copy, NULL);
}
