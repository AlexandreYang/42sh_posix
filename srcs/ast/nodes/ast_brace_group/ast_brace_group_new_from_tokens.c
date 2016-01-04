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

#include "ast/nodes/ast_brace_group.h"
#include "ast/nodes/ast_compound_list.h"

t_ast_brace_group	*ast_brace_group_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_brace_group		*ast_brace_group;
	t_lst					*copy;

	ast_brace_group = ast_brace_group_new();
	copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(copy);
	twl_lst_pop_back(copy);
	ast_brace_group->ast_compound_list = ast_compound_list_new_from_tokens(copy, ast);
	token_mgr_del(copy);
	if (ast_brace_group->ast_compound_list == NULL)
		return (NULL);
	return (ast_brace_group);
}