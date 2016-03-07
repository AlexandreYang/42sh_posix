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

#include "ast/nodes/ast_if_then.h"
#include "ast/nodes/ast_for_clause.h"

static void			iter_wordlist_fn(void *word_token, void *this_)
{
	t_ast_for_clause	*this;

	this = this_;
	shenv_shvars_set(shenv_singleton(), this->name, word_token, NULL);
	ast_compound_list_exec(this->do_group);
}

void				ast_for_clause_exec(t_ast_for_clause *this)
{
	t_lst			*wordlist;

	if (twl_lst_len(this->wordlist))
		wordlist = token_mgr_to_lst(this->wordlist);
	else
		wordlist = twl_lst_copy(shenv_singleton()->pos_params, NULL);
	twl_lst_iter(wordlist, iter_wordlist_fn, this);
	twl_lst_del(wordlist, NULL);
}
