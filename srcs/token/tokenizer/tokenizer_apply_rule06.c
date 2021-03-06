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
** Rule 6
**  If the current character is not quoted and can be used as the first
**  character of a new operator, the current token (if any) shall be delimited.
**  The current character shall be used as the beginning
**  of the next (operator) token.
*/

t_rule_status		tokenizer_apply_rule06(t_tokenizer *t)
{
	if (!t->cur_is_quoted
		&& tokenizer_utils_is_start_of_op(t, *t->curpos))
	{
		tokenizer_delimit(t);
		tokenizer_append_to_curtoken(t, 1);
		t->curpos++;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
