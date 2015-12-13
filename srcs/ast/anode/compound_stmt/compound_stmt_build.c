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

#include "utils.h"

#include "ast/anode/if_stmt.h"
#include "ast/anode/cmd_stmt.h"
#include "ast/anode/string_literal.h"

static bool			is_if_stmt(char *str)
{
	if (twl_str_starts_with(str, "if "))
		return (true);
	else
		return (false);
}

static int			ast_build_compound_stmt_lists(t_compound_stmt *compound_stmt, char *str)
{
	char				*not_comp_stmt;

	not_comp_stmt = twl_str_split_get(str, AST_SEPARATOR, 0);
	if ("TODO is_a_simple_cmd")
	{
		t_cmd_stmt	*cmd_stmt;
		cmd_stmt = cmd_stmt_new();
		twl_lst_push(compound_stmt->items, cmd_stmt);
		int	len = cmd_stmt_build(cmd_stmt, not_comp_stmt);
		return (len + twl_strlen(AST_SEPARATOR));
	}
	return (0);
}

int					compound_stmt_build(t_compound_stmt *compound_stmt,
																	char *str)
{
	int				len;
	int				total_len;

	total_len = twl_strlen(str);
	len = 0;
	while (len < total_len)
	{
		if (is_if_stmt(str + len))
		{
			t_if_stmt *if_stmt;
			if_stmt = if_stmt_new();
			twl_lst_push(compound_stmt->items, if_stmt);
			len += if_stmt_build(if_stmt, str + len);
		}
		else
		{
			len += ast_build_compound_stmt_lists(compound_stmt, str + len);
		}
	}
	return (len);
}
