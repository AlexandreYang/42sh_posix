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

#include "data.h"
#include "ast/ast.h"
#include "token/token_list_mgr.h"
#include "token/token_utils.h"
#include "ast/nodes/ast_for_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

static void				pop_word_list(t_ast_for_clause *this, t_lst *tokens)
{
	t_token			*first;

	while (twl_lst_len(tokens))
	{
		if (token_mgr_first_equ(tokens, ";")
			|| token_mgr_first_equ(tokens, "\n"))
			break ;
		first = twl_lst_pop_front(tokens);
		if (!first)
			break ;
		twl_lst_push_back(this->wordlist, token_copy(first));
	}
}

static t_ast_for_clause	*ast_for_clause_new_from_tokens_init(t_lst *tokens,
		struct s_ast *ast, t_token **open)
{
	t_ast_for_clause	*this;

	this = ast_for_clause_new();
	*open = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_add_to_open_stack(ast, "for");
		ast_set_error_msg_syntax_error_missing(ast, *open, "NAME token");
		ast_for_clause_del(this);
		return (NULL);
	}
	this->name = twl_strdup(token_mgr_first(tokens)->text);
	twl_lst_pop_front(tokens);
	if (!token_utils_is_valid_name(this->name))
	{
		ast_set_error_msg_syntax_error_near(ast, *open, "invalid NAME token");
		ast_for_clause_del(this);
		return (NULL);
	}
	token_mgr_pop_linebreak(tokens);
	return (this);
}

static t_ast_for_clause	*ast_for_clause_new_from_tokens_end(
		t_ast_for_clause *this, struct s_ast *ast, t_token *open)
{
	if (ast_has_error(ast) || this->do_group == NULL)
	{
		ast_set_error_msg_syntax_error_near(ast, open, NULL);
		ast_for_clause_del(this);
		return (NULL);
	}
	return (this);
}

t_ast_for_clause		*ast_for_clause_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_for_clause	*this;
	t_token				*open;

	if (!(this = ast_for_clause_new_from_tokens_init(tokens, ast, &open)))
		return (NULL);
	if (token_mgr_first_equ(tokens, "in"))
	{
		twl_lst_pop_front(tokens);
		if (twl_lst_len(tokens) == 0)
		{
			ast_add_to_open_stack(ast, "for");
			ast_set_error_msg_syntax_error_missing(ast, open, "in arguments");
			ast_for_clause_del(this);
			return (NULL);
		}
		pop_word_list(this, tokens);
	}
	token_mgr_pop_linebreak_colon_linebreak(tokens);
	if (twl_lst_len(tokens) == 0)
		ast_add_to_open_stack(ast, "for");
	this->do_group = ast_compound_list_new_from_tokens_wrap(tokens,
		"do", "done", ast);
	return (ast_for_clause_new_from_tokens_end(this, ast, open));
}
