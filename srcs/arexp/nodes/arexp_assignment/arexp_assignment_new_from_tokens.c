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

#include "token/token_mgr.h"
#include "data_utils.h"
#include "arexp/nodes/arexp_assignment.h"
#include "arexp/arexp.h"

static void				pop_assignment(t_arexp_assignment *assignment,
																t_lst *tokens)
{
	t_token				**assign;
	t_token				*token;

	while (42)
	{
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_VARIABLE)
			break ;
		token = twl_lst_get(tokens, 1);
		if (!token || !data_utils_arexp_is_assign(token->text))
			break ;
		assign = twl_malloc_x0(sizeof(t_token *) * 2);
		assign[0] = twl_lst_pop_front(tokens);
		assign[1] = twl_lst_pop_front(tokens);
		twl_lst_push_front(assignment->assign, assign);
	}
}

t_arexp_assignment		*arexp_assignment_new_from_tokens(t_lst *tokens)
{
	t_arexp_assignment	*assignment;
	t_arexp_condition	*condition;

	assignment = arexp_assignment_new();
	pop_assignment(assignment, tokens);
	condition = arexp_condition_new_from_tokens(tokens);
	if (arexp_has_error(arexp_singleton(NULL, false)))
	{
		arexp_assignment_del(assignment);
		arexp_condition_del(condition);
		return (NULL);
	}
	assignment->condition = condition;
	return (assignment);
}
