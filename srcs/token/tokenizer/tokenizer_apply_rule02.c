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

#include "token/tokenizer.h"

/*
** Rule 2
**  If the previous character was used as part of an operator and the
**  current character is not quoted and can be used with the current
**  characters to form an operator, it shall be used as part of that (operator)
**  token.
*/

t_rule_status		tokenizer_apply_rule02(t_tokenizer *t)
{
	if (!t->cur_is_quoted
		&& tokenizer_utils_can_form_operator(t, t->curtokenplus))
	{
		tokenizer_append_to_curtoken(t, 1);
		t->curpos++;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
