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

#ifndef AST_COMPOUND_LIST_H
# define AST_COMPOUND_LIST_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_utils.h"
# include "ast/ast_defines.h"

# include "ast/nodes/ast_list_item.h"

typedef struct				s_ast_compound_list
{
	t_lst					*ast_list_items;
}							t_ast_compound_list;

t_ast_compound_list			*ast_compound_list_new(void);
void						ast_compound_list_del(
										t_ast_compound_list *ast_compound_list);
void						ast_compound_list_del_void(void *this);
t_ast_compound_list			*ast_compound_list_new_from_tokens(t_lst *tokens,
															struct s_ast *ast);
t_ast_compound_list			*ast_compound_list_new_from_tokens_wrap(
														t_lst *tokens,
														char *open,
														char *close,
														struct s_ast *ast);
void						ast_compound_list_print_rec(
										t_ast_compound_list *ast_compound_list,
										int depth);
void						ast_compound_list_print_function(
										t_ast_compound_list *ast_compound_list,
										int depth);
void						ast_compound_list_print_function_seplast(
										t_ast_compound_list *ast_compound_list,
										int depth);
void						ast_compound_list_print_function_seplast_unfirst(
										t_ast_compound_list *ast_compound_list,
										int depth);
void						ast_compound_list_print_function_unfirst(
										t_ast_compound_list *ast_compound_list,
										int depth);

void						ast_compound_list_exec(
										t_ast_compound_list *ast_compound_list);
void						ast_compound_list_exec_ignore_errexit(
										t_ast_compound_list *ast_compound_list);
int							ast_compound_list_expan(
										t_ast_compound_list *ast_compound_list);

#endif
