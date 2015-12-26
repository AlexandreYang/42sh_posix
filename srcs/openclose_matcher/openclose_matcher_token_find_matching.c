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

#include "openclose_matcher.h"
#include "openclose_mgr.h"
#include "token_mgr.h"

static bool			find_open_start_fn(void *oc_, void *text)
{
	t_openclose		*oc;

	oc = oc_;
	return (twl_strequ(text, oc->open));
}

static void			resolve(t_openclose_matcher *matcher, t_lst *stack,
											t_lst *tokens, t_token *token)
{
	t_openclose		*open_pos;
	t_openclose		*oc;

	oc = twl_lst_last(stack);
	open_pos = twl_lst_find(matcher->oc_pairs, find_open_start_fn, token->text);
	if (oc && twl_strequ(token->text, oc->close))
	{
		twl_lst_pop(stack);
	}
	else if (open_pos)
	{
		twl_lst_push(stack, open_pos);
	}
	twl_lst_shift(tokens);
}

int					openclose_matcher_token_find_matching(
								t_openclose_matcher *matcher, t_lst *tokens)
{
	t_lst			*stack;
	t_lst			*tokens_copy;
	t_token			*token;

	stack = twl_lst_new();
	tokens_copy = twl_lst_copy(tokens, NULL);
	while ((token = twl_lst_first(tokens_copy)))
	{
		COUCOU;
		resolve(matcher, stack, tokens_copy, token);
		COUCOU;
		if (twl_lst_len(stack) == 0)
		{
		COUCOU;
			twl_lst_del(stack, NULL);
		COUCOU;
			return (twl_lst_len(tokens) - twl_lst_len(tokens_copy));
		}
	}
		COUCOU;
	openclose_mgr_print(stack);
	twl_lst_del(stack, NULL);
	return (-1);
}
