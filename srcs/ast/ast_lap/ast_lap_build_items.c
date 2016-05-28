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

#include "ast/ast_lap.h"
#include "alias/alias_mgr.h"

static bool is_reserved_word_delimiter(t_lst *tokens)
{
	return (data_utils_is_reserved_word_middle_end(
				token_mgr_first(tokens)->text)
			|| token_mgr_first_equ(tokens, ";;"));
}

static bool is_last_sep_that_require_more_tokens(t_token *token)
{
	return (token
		&& (twl_strequ(token->text, "&&")
			|| twl_strequ(token->text, "||")
			|| twl_strequ(token->text, "|"))
		);
}

static bool is_type_separator(t_ast_type type, t_token *token)
{
	return (token
		&& twl_lst_find(ast_lap_get_seps_list()[type],
			twl_strequ_void, token->text)
		);
}

/*
** Special case for list items
*/
static bool is_list_sep_followed_by_closing_parenthesis(t_lst *tokens,
							t_ast_type type, t_token *last_sep)
{
	return (type == AST_TYPE_LIST_ITEM && last_sep
		&& token_mgr_first_equ(tokens, ")"));
}

t_lst				*ast_lap_build_items(t_lst *tokens,
							t_ast_type type, struct s_ast *ast)
{
	void			*item;
	t_lst			*container;
	t_token			*last_sep;

	last_sep = NULL;
	container = twl_lst_new();
	while (42)
	{
		token_mgr_pop_linebreak(tokens);
		alias_mgr_expan_tokens(shenv_singleton()->shenv_alias, tokens, ast);
		if (twl_lst_len(tokens) == 0 || is_reserved_word_delimiter(tokens))
			break ;
		if (is_list_sep_followed_by_closing_parenthesis(tokens, type, last_sep))
			break ;
		last_sep = NULL;
		item = ast_lap_new_from_tokens_fns()[type](tokens, ast);
		if (ast_has_error(ast))
		{
			ast_lap_del_fns()[type](item);
			twl_lst_del(container, ast_lap_del_fns()[type]);
			return (NULL);
		}
		twl_lst_push_back(container, item);
		if (!is_type_separator(type, token_mgr_first(tokens)))
			break ;
		ast_lap_set_separator_fns()[type](item, token_mgr_first(tokens));
		last_sep = twl_lst_pop_front(tokens);
	}
	if (token_mgr_first_equ(tokens, "("))
	{
		ast_add_to_open_stack(ast, "(");
		ast_set_error_msg_syntax_error_near(ast, token_mgr_first(tokens), NULL);
		twl_lst_del(container, ast_lap_del_fns()[type]);
		return (NULL);
	}
	if (is_last_sep_that_require_more_tokens(last_sep))
	{
		ast_add_to_open_stack(ast, last_sep->text);
		ast_set_error_msg_syntax_error_near(ast, last_sep, NULL);
		twl_lst_del(container, ast_lap_del_fns()[type]);
		return (NULL);
	}
	return (container);
}
