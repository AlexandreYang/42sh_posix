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

#include "tokenizer.h"

/*  Rule 3
	If the previous character was used as part of an operator and the
	current character is not quoted and can be used with the current
	characters to form an operator, it shall be used as part of that (operator)
	token.
*/

int					tokenizer_apply_rule2(t_tokenizer *this)
{
	if (tokenizer_utils_is_prev_char_an_operator(this)
		&& tokenizer_utils_can_form_operator_with_prev(this))
	{
		this->tokentype = PREV_OPERATOR;
		tokenizer_append_to_curtoken(this);
		this->curpos++;
		return (1);
	}
	return (0);
}
