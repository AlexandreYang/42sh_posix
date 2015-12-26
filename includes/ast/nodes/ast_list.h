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

#ifndef AST_LIST_H
# define AST_LIST_H

# include "basics.h"

# include "ast/ast_utils.h"

typedef struct		s_ast_list
{
	struct s_ast_list		*list;
	t_lst					*tokens;
}					t_ast_list;

t_ast_list			*ast_list_new(void);
void				ast_list_del(t_ast_list *ast_list);

t_ast_list			*ast_list_new_from_tokens(t_lst *tokens);
void				ast_list_print_rec(
							t_ast_list *ast_list,
							int depth);
#endif
