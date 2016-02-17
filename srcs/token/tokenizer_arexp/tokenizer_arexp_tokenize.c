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

t_rule_fn			g_tokenizer_rule_fns[1] = {
					tokenizer_arexp_rule01,
					tokenizer_arexp_rule02,
					tokenizer_arexp_rule03,
					tokenizer_arexp_rule04,
					tokenizer_arexp_rule05,
					tokenizer_arexp_rule06,
					NULL};

t_lst				*tokenizer_arexp_tokenize(char *input)
{
	t_rule_status	status;
	t_tokenizer		*t;
	int				i;
	t_lst			*tokens;

	t = tokenizer_new(input);
	t->tokens = twl_lst_new();
	status = RULE_STATUS_NONE;
	while (true)
	{
		i = 0;
		while (g_tokenizer_rule_fns[i])
		{
			status = g_tokenizer_rule_fns[i](t);
			if (status != RULE_STATUS_NOT_APPLIED)
				break ;
			i++;
		}
		if (status == RULE_STATUS_END_OF_INPUT)
			break ;
	}
	tokens = t->tokens;
	t->tokens = NULL;
	tokenizer_del(t);
	return (tokens);
}
