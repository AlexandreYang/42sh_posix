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

#include "basics.h"
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_quote_removal.h"
#include "patmatch.h"

static void		iter_fn(void *expan_token_)
{
	t_expan_token *expan_token;

	expan_token = expan_token_;
	if (expan_token->exec_expan)
	{
		expan_token->exec_expan(expan_token);
	}
	if (expan_token->origin != PARAMETER_SUBSTITUTION_WORD)
	{
		expan_exec_pattern_matching(expan_token);
		expan_quote_removal(&expan_token->res);
	}
}

void			expan_exec(t_lst *expan_tokens)
{
	(void)expan_tokens;
	twl_lst_iter0(expan_tokens, iter_fn);
}
